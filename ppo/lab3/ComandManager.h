#ifndef COMANMANAGER_H
#define COMANMANAGER_H
#include "TreeModel.h"
#include <QTreeView>
#include "LoadManager.h"
#include <QTreeWidget>
#include <Student.h>
#include "InfoByTree.h"
typedef QVector<Student> Students;


class ComandManager
{
public:
    ComandManager();


    void changeInfo(QModelIndexList indxList, QVector<QVariant> nextData);
    void insertInfo(QModelIndex parent, QVector<QVariant> data);
    void deleteInfo(QModelIndex indx);

    void loadGroupsFromJson(QString &fileName);
    void saveGroupsToJson(QString &fileName);

    void showInfo(QTreeWidget *viewer);
    void setTreeView(QTreeView *viewer);

    TreeModel *getModel();

    void clearStudents();
private:
    //SaveManager saveManager;
    LoadManager loadManager;
    Students *groups;
    TreeModel *treeModel;
    InfoByTree viewer;

};

#endif // COMANMANAGER_H
