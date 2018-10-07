#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

/*
extern "C" {
    extern void dswap_(int*,double*,int*,double*,int*);
    extern void daxpy_(int*,double*,double*,int*,double*,int*);
    extern void dscal_(int*,double*,double*,int*);
}
*/

template <class field>
class vector
{
public:
    vector(int number,field initial=0)
    {
        u = new field[number];
        length = number;
        for(int lupe=0;lupe<number;++lupe)
        {
            u[lupe] = initial;
        }
    }

    ~vector()
    {
      delete [] u;
    }

    field& operator [] (int which)
    {
        return(u[which]);
    }

    field operator [] (int which) const
    {
        return(u[which]);
    }

    explicit operator field*() {return u;}

private:
    field *u;
    int length;
};


template <class field>
class matrix
{
public:
    matrix(int numRows,int numColumns,field initial=0)
    {
        rows    = numRows;
        columns = numColumns;
        u = new field*[rows];
        u[0] = new field[rows*columns];
        for(int rowLupe=0;rowLupe<rows;++rowLupe)
        {
            u[rowLupe] = u[0] + rowLupe*columns;
            for(int columnLupe=0;columnLupe<columns;++columnLupe)
            {
                u[rowLupe][columnLupe] = initial;
            }
        }
    }

    ~matrix()
    {
        delete u[0];
        delete [] u;
    }

    // Routine to get a pointer to one row of the matrix using the [] operator
    field*& operator [] (int which)
    {
        if(which >= rows)
        {
            std::cout << "Row number out of bounds" << std::endl;
            exit(1);
        }
        return(u[which]);
    }

    // Routine to get a pointer to one row of the matrix using the [] operator
    field* operator [] (int which) const
    {
        if(which >= rows)
        {
            std::cout << "Row number out of bounds" << std::endl;
            exit(1);
        }
        return(u[which]);
    }

    // Routine to get the data when casting the type
    explicit operator field*() {return u[0];}

    // routine to get the number of rows in the matrix
    int getNumberRows() { return(rows);}

    // routine to get the number of columnss in the matrix
    int getNumberColumns() { return(columns);}


    /* **************************************************************
     * Routine to swap two given rows in the matrix.
     * ************************************************************** */
    void swapRows(int firstRow,int secondRow)
    {
        // Set up the pointers to point at the first entry in each row.
        field *ptr1 = u[firstRow];
        field *ptr2 = u[secondRow];

        // intermediate values and loop variables required for the loop.
        field tmp;
        int lupe;

        for(lupe=0;lupe<columns;++lupe)
        {
            // go through each entry in the vectors and exchange them.
            tmp = *ptr1;
            *ptr1++ = *ptr2;
            *ptr2++ = tmp;
        }
    }

    /* **************************************************************
     * Routine to add one row of the matrix multipled by a constant
     * to another row in the matrix.
     * ************************************************************** */
    void daxpy(field scaleValue,int changedRow,int sourceRow,int startColumn)
    {
        // Set up the pointers to point at the first entry in each row.
        field *ptr1 = u[changedRow]+startColumn;
        field *ptr2 = u[sourceRow]+startColumn;

        for(int lupe=startColumn;lupe<columns;++lupe)
        {
            // go through each entry and perform the scale/add opteration
            *ptr1++ += scaleValue*(*ptr2++);
        }
    }

    /* **************************************************************
     * Routine to go through a row in the matrix and multiply by a
     * scalar value.
     * ************************************************************** */
    void dscal(field scaleValue,int whichRow,int startColumn)
    {
        // set up the pointer to point at the first entry in the row
        field *ptr = u[whichRow] + startColumn;

        // scale every entry in the vector.
        for(int lupe=startColumn;lupe<columns;++lupe)
            *ptr++ *= scaleValue;
    }

    /* **************************************************************
     * Routine to determine the Reduced Row Echelon Form of the matrix.
     * Performs the RREF in place with the current matrix.
     * ************************************************************** */
    void RREF()
    {
        // define various required variables.
        int outerLupe;
        int innerLupe;
        int currentPivotColumn = 0; // used to indicate the current pivot column

        // Go through each row in the matrix.
        // Figure out a new pivot row and then zero out the entries in the column
        // and and below the current row.
        for(outerLupe=0;(outerLupe<rows) && (currentPivotColumn<columns);++outerLupe)
        {

            // First figure out the current pivot.
            innerLupe = outerLupe; // assume that the pivot is in the first row available.
            while(currentPivotColumn < columns)
            {
                // Start with the current row and work down.
                if((fabs(u[innerLupe][currentPivotColumn])>1e-9))
                {
                    // This entry in this column and row non-zero. Stop here and use this.
                    break;
                }
                else
                {
                    // The entry in this column is essentially zero.
                    innerLupe += 1;    // check the next row.
                    if(innerLupe>=rows)
                    {
                        // We have hit the last row. Everything must be zero. Move over to the next column and start over.
                        innerLupe = outerLupe;
                        currentPivotColumn += 1;
                    }
                }
            }

            if (currentPivotColumn<columns)
            {
                // The current row and pivot are valid.
                // Can zero out the other rows in the current column

                // First see if we need to swap rows.
                if(innerLupe != outerLupe)
                {
                    // The next non-zero row is not the current row.
                    swapRows(innerLupe,outerLupe);
                }

                // zero out everything above the current pivot
                for(int lupe=0;lupe<outerLupe;++lupe)
                {
                    if(fabs(u[lupe][currentPivotColumn]) > 1e-9 )
                    {
                        // Need to zero out the column in this row....
                        daxpy(-u[lupe][currentPivotColumn]/u[outerLupe][currentPivotColumn],
                              lupe,outerLupe,currentPivotColumn);
                    }
                }

                // zero out everything below the current pivot
                for(int lupe=outerLupe+1;lupe<rows;++lupe)
                {
                    if(fabs(u[lupe][currentPivotColumn]) > 1e-9 )
                    {
                        // Need to zero out the column in this column....
                        daxpy(-u[lupe][currentPivotColumn]/u[outerLupe][currentPivotColumn],
                              lupe,outerLupe,currentPivotColumn);
                    }
                }

                // scale the row so that the entry in pivot column is equal to one.
                dscal(1.0/u[outerLupe][currentPivotColumn],outerLupe,currentPivotColumn);

            }

            // About to go on to the next row. Update the current pivot column to use the next column
            currentPivotColumn += 1;
        }

    }

private:
    field **u;
    int rows;
    int columns;
};



#endif // VECTOR_H
