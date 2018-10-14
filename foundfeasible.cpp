/* ************************************************************************************************
 * Author: Kelly Black
 * Date: October 2018
 *
 * Program to calculate the relative weights associated with each flow in a tropic system
 * with respect to the relative importance. Formula developed with Caner Kazanci, Malcolm
 * Adams, Stuart Whipple, Aladeen Al Basheer, and Bernie Patton.
 *
 * This is a class that is used to help keep track of one set of vectors. It uses an
 * insertion sort to add new columns sequentially. This way the tree used in the
 * CheckedColumnsTree class will not consider order.
 *
 * Copyright © 2018 Kelly Black
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the “Software”), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * ************************************************************************************************ */

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

