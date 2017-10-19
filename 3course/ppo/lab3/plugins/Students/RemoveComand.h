#ifndef REMOVECOMAND_H
#define REMOVECOMAND_H
#include "TreeModel.h"

#include "Comands.h"
#include <QByteArray>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QStringList>
#include <QTreeView>
#include <QUndoCommand>
#include <QVector>
#include <QJsonObject>
#include <iostream>
#include "TreeModel.h"

class RemoveCommand : public BaseCommand {

public:
    RemoveCommand(QModelIndex indx, QVector<QVector<QVariant> > backData, TreeModel *_treeModel);
    ~RemoveCommand();

    void undo() override;

    void redo() override;

private:
    QVector<QVector<QVariant> > data;
    QModelIndex index;
    QModelIndex parent;
    TreeModel *treeModel;

};

#endif // REMOVECOMAND_H
