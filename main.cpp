#include <iostream>
#include <iomanip>

#include "vector.h"

//using namespace std;

/*
extern "C" {
    extern void dswap_(int*,double*,int*,double*,int*);
    extern void daxpy_(int*,double*,double*,int*,double*,int*);
}
*/

// Routine to print out a vector to the console
template <class field>
void printVector(vector<field> &v)
{
    std::cout << v[0];
    for(int lupe=1;lupe<v.getLength();++lupe)
        std::cout << "," << v[lupe];
    std::cout << std::endl;
}

// Routine to print out an array to the console.
template <class field>
void printArray(matrix<field> &A,int row,int col)
{
    int innerLupe;
    int outerLupe;


    std::cout << std::endl << std::endl << row << "-" << col << std::endl << "      ";

    // Print out the top row that has column numbers
    for(innerLupe=0;innerLupe<col;++innerLupe)
    {
        std::cout <<  "(" << std::setw(2) << innerLupe << ") ";
    }
    std::cout << std::endl;

    for (outerLupe=0;outerLupe<row;++outerLupe)
    {
        std::cout << std::endl << "(" << outerLupe << ")" << row << " ";
        for(innerLupe=0;innerLupe<col;++innerLupe)
        {
            std::cout <<  std::setw(4) << A[outerLupe][innerLupe]  << " ";
        }
    }
    std::cout << std::endl;
}


// Routine to see if a given column is already listed in the
// vector of indicies to check.
bool columnExists(vector<int> *indicies,int currentRow,int value)
{
    // Go through all of the previous entries in the vector.
    for(int lupe=0;lupe<currentRow;++lupe)
        if((*indicies)[lupe]==value)  // If the value exists return true. All done!
            return(true);

    // If we get here the value was not found.
    return(false);
}

// Routine to see if a given collection of columns has already been considered.
// The idea is that if the coresponding entries in the RREF are non-zero, and
// the column numbers are in descending order, then the set has already been
// considered.
bool columnsConsidered(matrix<double> *rref,
                       vector<int> *indicies,
                       int currentRow,
                       int currentColumn)
{

    bool considered = false;

    //std::cout << "checking: " << (*indicies)[currentRow] << "/" << currentRow << "/" << currentColumn << " " << std::endl;
    //printVector(*indicies);
    for(int lupe=0;!considered && (lupe<(currentRow-1));++lupe)
    {
        if((*indicies)[lupe]>(*indicies)[currentRow])
        {
            for(int rowCheck=0;!considered && (rowCheck<(currentRow-1));++rowCheck)
            {
                /*
                std::cout << std::setw(5) << (*rref)[rowCheck][(*indicies)[rowCheck]]
                          << std::setw(5) << (*rref)[currentRow][(*indicies)[rowCheck]]
                          << std::setw(5) << (*rref)[rowCheck][currentColumn]
                          << std::setw(5) << (*rref)[currentRow][currentColumn]
                               << std::endl;
                               */
                 considered = considered ||
                         (fabs((*rref)[rowCheck][(*indicies)[rowCheck]] *
                            (*rref)[currentRow][(*indicies)[rowCheck]] *
                            (*rref)[rowCheck][currentColumn] *
                            (*rref)[currentRow][currentColumn]) > 1e-4 );
            }
        }
    }

    // if we get here then the set of columns have not been considered previously.
    return(considered);
}

// http://www.netlib.org/lapack/lug/node80.html
// http://www.netlib.org/lapack/explore-html/d7/d3b/group__double_g_esolve_ga5ee879032a8365897c3ba91e3dc8d512.html#ga5ee879032a8365897c3ba91e3dc8d512
// http://www.netlib.org/lapack/explore-html/dd/d9a/group__double_g_ecomputational_ga188b8d30443d14b1a3f7f8331d87ae60.html#ga188b8d30443d14b1a3f7f8331d87ae60

/* *******************************************************************************
 * Routine to go through the RREF of the matrix and get all combinations of the
 * columns that have non-zero entries in the RREF of the matrix.
 *
 * This is a recursive routine. If starts with the top row and goes through each
 * column with a non-zero entry. For each of those entries it then calls the routine
 * to go through the next row and check each column for the next row. (Repeat!)
 * ******************************************************************************* */
void checkColumns(matrix<double> *rref, vector<int> *indicies,int currentRow)
{
    // Go through each column for the current row. Check to see which entries are
    // non-zero....
    int lupe;
    for(lupe=0;lupe<rref->getNumberColumns();++lupe)
    {
        (*indicies)[currentRow] = lupe;
        if((fabs((*rref)[currentRow][lupe])>1.0e-9) &&
                (!columnExists(indicies,currentRow,lupe)) &&
                (!columnsConsidered(rref,indicies,currentRow,lupe)))
        {
            // This entry in the RREF matrix is non-zer0.
            // The column has also not been checked previously.
            // It is a potential column to check.

            // Add this column to the list of columns currently under consideration.
            if( (currentRow+1) >= rref->getNumberRows())
            {
                // We now have a full list of columns to check.
                printVector(*indicies);
            }
            else
            {
                // We need at least one more column to check.
                // search using the next row in the RREF matrix.
                checkColumns(rref,indicies,currentRow+1);
            }
        }
    }
}

int main()
{
    vector<double> v(10,1.0);
    matrix<double> A(4,8,0.0);
    vector<int>    indicies(A.getNumberRows(),-1);
    int innerLupe;
    int outerLupe;

    //double* u = (double*)A;
    for (innerLupe=0;innerLupe<8;++innerLupe)
        A[0][innerLupe] = 1.0;
    A[0][7] = 0;
    A[0][6] = 0;

    for (innerLupe=0;innerLupe<8;innerLupe+=2)
        A[1][innerLupe] = 1.0;

    for (innerLupe=0;innerLupe<8;++innerLupe+=3)
        A[2][innerLupe] = 1.0;

    double val = 1.0;
    for (innerLupe=0;innerLupe<8;++innerLupe)
    {
        A[3][innerLupe] = val;
        val *= -1.0;
    }
    A[3][0] = -1.0;

    printArray<double>(A,4,8);
    std::cout << std::endl << std::endl << "Starting" << std::endl;
    A.RREF();
    printArray<double>(A,4,8);
    checkColumns(&A,&indicies,0);
    std::cout << "Done" << std::endl;

    return 0;
}

