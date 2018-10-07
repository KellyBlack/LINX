#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

extern "C" {
    extern void dswap_(int*,double*,int*,double*,int*);
    extern void daxpy_(int*,double*,double*,int*,double*,int*);
    extern void dscal_(int*,double*,double*,int*);
}


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

    field*& operator [] (int which)
    {
        if(which >= rows)
        {
            std::cout << "Row number out of bounds" << std::endl;
            exit(1);
        }
        return(u[which]);
    }

    field* operator [] (int which) const
    {
        if(which >= rows)
        {
            std::cout << "Row number out of bounds" << std::endl;
            exit(1);
        }
        return(u[which]);
    }

    explicit operator field*() {return u[0];}

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
        //int skip = 1;
        //dswap_(&columns,u[firstRow],&skip,u[secondRow],&skip);
    }

    void RREF()
    {
        int outerLupe;
        int innerLupe;
        int currentPivotColumn = 0;

        for(outerLupe=0;outerLupe<rows;++outerLupe)
        {

            // First figure out the current pivot.
            innerLupe = outerLupe; // assume that the pivot is in the first row available.
            while(currentPivotColumn < columns)
            {
                std::cout << "Trying row " << innerLupe << std::endl;
                // Start with the current row and work down.
                if((fabs(u[innerLupe][currentPivotColumn])>1e-9))
                {
                    // This entry in this column and row non-zero. Stop here and use this.
                    std::cout << " looks good: " << currentPivotColumn << " - " << innerLupe << " row " << outerLupe << std::endl;
                    break;
                }
                else
                {
                    // The entry in this column is essentially zero.
                    innerLupe += 1;    // check the next row.
                    if(innerLupe>=rows)
                    {
                        std::cout << "Need to shift the pivot column :-( " << currentPivotColumn << std::endl;
                        // We have hit the last row. Everything must be zero. Move over to the next column and start over.
                        innerLupe = outerLupe;
                        currentPivotColumn += 1;
                    }
                }
            }
            std::cout << "Pivot: " << currentPivotColumn << " row: " << innerLupe << std::endl;

            // zero out everything below the current pivot

        }

        //int skip = 1;
        //dscal_(&columns,&mul,u[2],&skip);
    }

private:
    field **u;
    int rows;
    int columns;
};



#endif // VECTOR_H
