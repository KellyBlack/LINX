#include <iostream>
#include <iomanip>

#include "foundfeasible.h"

FoundFeasible::FoundFeasible()
{

}

void FoundFeasible::clearList()
{
    while(columns.size()>0)
        columns.pop_back();
}

void FoundFeasible::printList()
{
    std::list<int>::iterator listValues;
    for(listValues=columns.begin();listValues!=columns.end();++listValues)
    {
        std::cout << *listValues << "-";
    }
    std::cout << std::endl;
}

void FoundFeasible::addColumn(int value)
{
    std::list<int>::iterator listValues;
    for(listValues=columns.begin();listValues!=columns.end();++listValues)
    {
        if(value < *listValues)
        {
            // Need to insert the value before the current entry in the list.
            columns.insert(listValues,value);
            return;
        }
    }
    // if we get here then the value needs to be appended at the end
    columns.push_back(value);
}

std::ostream& operator<<(std::ostream& os, FoundFeasible& v)
{
    std::list<int>::iterator values;
    for(values=v.columns.begin();values!=v.columns.end();++values)
        os << *values << "-";
    return(os);
}

bool FoundFeasible::match(Vector<int> *indicies)
{
    // See if the two lists have the same length.
    bool found = (std::size_t)indicies->getLength() == columns.size();
    //std::cout << "   Checking " << *indicies << " comparing to me " << *this << "   initial check: " << found << std::endl;

    std::list<int>::iterator listValues;
    for(int columnLupe = 0;found && (columnLupe<indicies->getLength());++columnLupe)
    {
        // for each entry in the vector that was passed, see if we can find a match.
        // Note we assume that each number in the list is distinct.
        bool located = false;
        for(listValues=columns.begin();!located && listValues!=columns.end() && *listValues <= (*indicies)[columnLupe];++listValues)
        {
            // Go through the list of numbers that this data structure is keeping track of.
            // See if any one matches.
            located = located || ((*indicies)[columnLupe]==*listValues);
        }
        found = found && located;
    }
    //std::cout << " match: " << found << std::endl;
    return(found);
}

int FoundFeasible::length()
{
    return((int)columns.size());
}

std::list<int>::iterator FoundFeasible::begin(){return(columns.begin());}
std::list<int>::iterator FoundFeasible::end(){return(columns.end());}
void FoundFeasible::startIteration(){currentPos=begin();}
void FoundFeasible::next(){++currentPos;}
bool FoundFeasible::iterationDone(){return(currentPos!=end());}
int FoundFeasible::currentValue(){return(*currentPos);}

