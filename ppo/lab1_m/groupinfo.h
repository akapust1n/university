#ifndef GROUPINFO_H
#define GROUPINFO_H
#include "treemodel.h"
#include "treeitem.h"
#include <QJsonArray>

class GroupInfo
{
public:
    GroupInfo(QAbstractItemModel *_model);
    QString getGroupInfo(QString group);
    QJsonArray getArray(QString group)  ;
private:
    TreeModel *model;
    QJsonArray document;
};

#endif // GROUPINFO_H
