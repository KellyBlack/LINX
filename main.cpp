#include <iostream>

#include "vector.h"

using namespace std;

int main()
{
    vector<double> v(10,1.0);
    int lupe;
    for(lupe=0;lupe<10;++lupe)
    {
        v[lupe] = (double)lupe;
        cout << lupe << ": " << v[lupe] << endl;
    }
    return 0;
}
