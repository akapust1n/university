#include "ComandManager.h"

#include <QFileDialog>


ComandManager::ComandManager()
{

}

void ComandManager::changeInfo(QModelIndexList indxList, QVector<QVariant> nextData)
{
    for (int i = 0; i < indxList.size(); i++)
        treeModel->setData(indxList.at(i), nextData.at(i));
}

void ComandManager::insertInfo(QModelIndex parent, QVector<QVariant> data)
{
    treeModel->insertRows(treeModel->rowCount(parent), 1, parent);

    for (int i = 0; i < data.size(); i++)
        treeModel->setData(parent.child(treeModel->rowCount(parent) - 1, i), data.at(i));
}

void ComandManager::deleteInfo(QModelIndex indx)
{
    treeModel->removeRows(indx.row(), 1, indx.parent());
}

void ComandManager::loadGroupsFromJson(QString &fileName)
{
    treeModel = loadManager.loadFromJson(fileName);
}

void ComandManager::saveGroupsToJson(QString &fileName)
{
    //saveManager.saveToJson(treeModel, fileName);
}

void ComandManager::showInfo(QTreeWidget *viewer)
{
    //viewer.showInfo(viewer, *groups);
}

void ComandManager::setTreeView(QTreeView *viewer)
{
    viewer->setModel(treeModel);
}

TreeModel *ComandManager::getModel()
{
    return treeModel;
}

void ComandManager::clearStudents()
{
    delete treeModel;
}
