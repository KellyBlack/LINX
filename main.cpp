#include <iostream>

#include "vector.h"

using namespace std;

int main()
{
    vector<double> v(10,1.0);
    matrix<double> A(10,5,1.0);
    int innerLupe;
    int outerLupe;

    double* u = (double*)v;
    for(innerLupe=0;innerLupe<10;++innerLupe)
    {
        u[innerLupe] = (double)innerLupe;
        cout << innerLupe << ": " << v[innerLupe] << endl;
    }

    cout << endl << endl;
    u = (double*)A;
    double *ptr = (double*)A;
    for (outerLupe=0;outerLupe<10;++outerLupe)
    {
        for(innerLupe=0;innerLupe<5;++innerLupe)
        {
            A[outerLupe][innerLupe] = outerLupe*10+innerLupe;
            cout << outerLupe << "," << innerLupe << " : " << A[outerLupe][innerLupe] << endl;
        }
    }
    for (outerLupe=0;outerLupe<10;++outerLupe)
    {
        for(innerLupe=0;innerLupe<5;++innerLupe)
        {
            cout << outerLupe << "," << innerLupe << " : " << *ptr++ << " - " << u[innerLupe+5*outerLupe] << endl;
        }
    }

    return 0;
}
