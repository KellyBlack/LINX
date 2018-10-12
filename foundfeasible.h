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
    int length();

    // Define the iterators used to step through the columns.
    std::list<int>::iterator begin();
    std::list<int>::iterator end();
    void startIteration();
    void next();
    bool iterationDone();
    int currentValue();

private:
    std::list<int> columns;
    std::list<int>::iterator currentPos;
};

#endif // FOUNDFEASIBLE_H
