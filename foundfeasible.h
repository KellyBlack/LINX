#ifndef FOUNDFEASIBLE_H
#define FOUNDFEASIBLE_H

#include <list>
//#include <vector>
#include "vector.h"

class FoundFeasible
{
public:
    FoundFeasible();

    friend std::ostream& operator<<(std::ostream& os, FoundFeasible& v);
    void clearList();
    void printList();
    void addColumn(int value);
    bool match(Vector<int> *indicies);

private:
    std::list<int> columns;
};

#endif // FOUNDFEASIBLE_H
