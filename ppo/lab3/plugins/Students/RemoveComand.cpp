#include "RemoveComand.h"

RemoveCommand::RemoveCommand(QModelIndex indx, QVector<QVector<QVariant> > backData, TreeModel* _treeModel)
    : index(indx)
    , data(backData)
    , parent(indx.parent())
    , treeModel(_treeModel)
{
}

RemoveCommand::~RemoveCommand() {}
void RemoveCommand::undo()
{
    treeModel->insertRows(treeModel->rowCount(parent), 1, parent);

    for (int i = 0; i < data.size(); i++)
        treeModel->setData(parent.child(treeModel->rowCount(parent) - 1, i), data.first().at(i));
    int row = 0;
    while (parent.child(row, 0).isValid()) {
        index = parent.child(row, 0);
        row++;
    }

    for (int i = 1; i < data.size(); i++) {

        treeModel->insertRows(treeModel->rowCount(parent), 1, parent);

        for (int i = 0; i < data.size(); i++)
            treeModel->setData(parent.child(treeModel->rowCount(parent) - 1, i), data.at(i).at(i));
    }
}

void RemoveCommand::redo()
{
    treeModel->removeRows(index.row(), 1, index.parent());
}
