#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

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
        int skip = 1;
        dswap_(&columns,u[firstRow],&skip,u[secondRow],&skip);
    }

    void RREF()
    {
        double mul = 1.0/u[2][0];
        std::cout << "Multiplier: " << mul << std::endl;
        int skip = 1;
        dscal_(&columns,&mul,u[2],&skip);
    }

private:
    field **u;
    int rows;
    int columns;
};



#endif // VECTOR_H
