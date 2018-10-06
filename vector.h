#ifndef VECTOR_H
#define VECTOR_H

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
        return(u[which]);
    }

    field* operator [] (int which) const
    {
        return(u[which]);
    }

    explicit operator field*() {return u[0];}

private:
    field **u;
    int rows;
    int columns;
};



#endif // VECTOR_H
