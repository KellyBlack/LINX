#ifndef CHECKEDCOLUMNSTREE_H
#define CHECKEDCOLUMNSTREE_H

#include <vector>

#include "vector.h"
#include "foundfeasible.h"

class CheckedColumnsTree
{
public:
    CheckedColumnsTree();
    CheckedColumnsTree(int width,int depth);

    bool checkColumn(FoundFeasible *indicies);

    void setWidth(int width);
    void setDepth(int depth);
    int getWidth();
    int getDepth();

    struct ColumnTree
    {
        bool value;
        ColumnTree *nextColumn;
    };

private:
    int maxWidth;
    int maxDepth;
    ColumnTree *checked;
};

#endif // CHECKEDCOLUMNSTREE_H
