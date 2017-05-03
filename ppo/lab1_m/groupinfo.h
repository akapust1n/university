#ifndef GROUPINFO_H
#define GROUPINFO_H
#include "treemodel.h"
#include "treeitem.h"

class GroupInfo
{
public:
    GroupInfo(QAbstractItemModel *_model);
    QString getGroupInfo(QString group);
private:
    TreeModel *model;
};

#endif // GROUPINFO_H
