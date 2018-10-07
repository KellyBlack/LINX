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
        std::cout << std::endl << "(" << outerLupe << ")" << row << std::endl;
        for(innerLupe=0;innerLupe<col;++innerLupe)
        {
            std::cout <<  A[outerLupe][innerLupe]  << "  ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    vector<double> v(10,1.0);
    matrix<double> A(4,8,0.0);
    int innerLupe;
    int outerLupe;

    //double* u = (double*)A;
    for (innerLupe=0;innerLupe<8;++innerLupe)
        A[0][innerLupe] = (double)innerLupe;

    for (innerLupe=0;innerLupe<8;++innerLupe)
        A[1][innerLupe] = 2.0*(double)innerLupe;

    for (innerLupe=0;innerLupe<8;++innerLupe)
        A[2][innerLupe] = 0.0; //3.0+(double)innerLupe;

    for (innerLupe=0;innerLupe<8;++innerLupe)
        A[3][innerLupe] = 0.0; //4.0;

    printArray<double>(A,4,8);
    std::cout << "Starting" << std::endl;
    A.swapRows(1,0);
    printArray<double>(A,4,8);
    std::cout << "Done" << std::endl;

    /*
    std::cout << std::endl << std::endl << "Starting" << std::endl;
    A.RREF();
    printArray<double>(A,4,8);
    std::cout << "Done" << std::endl;
    */
    return 0;
}

