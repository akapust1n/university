#ifndef TREE_H
#define TREE_H
#include <QTreeView>
#include <TreeModel.h>

class Tree
{
public:
    Tree();
    TreeModel *treeModel;
    QTreeView *treeView;
};

#endif // TREE_H
