#include "checkedcolumnstree.h"

CheckedColumnsTree::CheckedColumnsTree()
{
    setWidth(0);
    setDepth(0);
    checked = NULL;
}

CheckedColumnsTree::CheckedColumnsTree(int width,int depth)
{
    setWidth(width);
    setDepth(depth);
    checked = new ColumnTree[width];
    for(int lupe=0;lupe<width;++lupe)
    {
        checked[lupe].value = false;
        checked[lupe].nextColumn = NULL;
    }
}

bool CheckedColumnsTree::checkColumn(FoundFeasible *indicies)
{
    int width  = getWidth();
    int depth  = getDepth();

    // go through the tree and see if this thing exists. If not add it.
    ColumnTree *current = checked;
    bool exists = true;
    indicies->startIteration();
    for(int depthLupe=0;depthLupe<depth-1;++depthLupe)
    {
        // for each item in indicies see if the level in the tree exists.
        // Note that we know the full depth of the tree in advance which allows
        // to use prev. for loop.
        if(current[indicies->currentValue()].nextColumn==NULL)
        {
            // This branch of the tree does not exist.
            // Create a new branch and add it to the tree.
            ColumnTree *newBranch = new ColumnTree[width];
            for(int lupe=0;lupe<width;++lupe)
            {
                newBranch[lupe].nextColumn = NULL;
                newBranch[lupe].value = false;
            }
            current[indicies->currentValue()].nextColumn = newBranch;
            exists = false;
        }
        // Move the pointer down to the next level of the tree.
        current = current[indicies->currentValue()].nextColumn;
        indicies->next();
    }
    exists = exists && current[indicies->currentValue()].value;
    current[indicies->currentValue()].value = true;
    return(exists);
}

void CheckedColumnsTree::setWidth(int width) {maxWidth=width;}
void CheckedColumnsTree::setDepth(int depth) {maxDepth=depth;}
int CheckedColumnsTree::getWidth(){return(maxWidth);}
int CheckedColumnsTree::getDepth(){return(maxDepth);}
