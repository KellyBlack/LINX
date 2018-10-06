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

private:
    double *u;
    int length=0;
};



#endif // VECTOR_H
