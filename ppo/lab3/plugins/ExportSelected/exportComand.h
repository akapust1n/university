#ifndef EXPORTCOMAND_H
#define EXPORTCOMAND_H


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
#include <memory>

class exportComand : public BaseCommand {

public:
   exportComand(QModelIndex _selected, QString _filename, TreeModel *_treeModel);


    ~ exportComand() {};

    virtual void undo();

    virtual void redo();

private:
    QModelIndex selected;
    QString filename;
    TreeModel *treeModel;
};
#endif // EXPORTCOMAND_H
