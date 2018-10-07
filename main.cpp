#include <iostream>

#include "vector.h"

//using namespace std;

extern "C" {
    extern void dswap_(int*,double*,int*,double*,int*);
    extern void daxpy_(int*,double*,double*,int*,double*,int*);
}

template <class field>
void printArray(matrix<field> &A,int row,int col)
{
    int innerLupe;
    int outerLupe;

    std::cout << std::endl << std::endl << row << "-" << col << std::endl;
    for (outerLupe=0;outerLupe<row;++outerLupe)
    {
        std::cout << std::endl << "(" << outerLupe << ")" << row << " ";
        for(innerLupe=0;innerLupe<col;++innerLupe)
        {
            std::cout <<  A[outerLupe][innerLupe]  << "  ";
        }
    }
    std::cout << std::endl;
}

void checkColumns(matrix<double> *rref, int currentRow)
{
    //std::cout << " Checking columns " << currentRow << " " << rref->getNumberColumns() << std::endl;
    if(currentRow >= rref->getNumberRows())
    {
        std::cout << std::endl << "done" << std::endl;
        return;
    }

    int lupe;
    for(lupe=0;lupe<rref->getNumberColumns();++lupe)
    {
        if(fabs((*rref)[currentRow][lupe])>1.0e-9)
        {
            // This entry in the RREF matrix is non-zer0. It is a potential column to check.
            std::cout << "  (" << currentRow << "," << lupe << ")";

            if( (currentRow+1) >= rref->getNumberRows())
                std::cout << std::endl;
            else
                checkColumns(rref,currentRow+1);

        }
    }
}

int main()
{
    vector<double> v(10,1.0);
    matrix<double> A(4,8,0.0);
    int innerLupe;
    int outerLupe;

    //double* u = (double*)A;
    for (innerLupe=0;innerLupe<8;++innerLupe)
        A[0][innerLupe] = 1.0;

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
    checkColumns(&A,0);
    std::cout << "Done" << std::endl;

    return 0;
}

