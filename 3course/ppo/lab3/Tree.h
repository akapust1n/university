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
    QString *kindTree = nullptr;
};

#endif // TREE_H
