#ifndef EXPORTSTUDENTCOMAND_H
#define EXPORTSTUDENTCOMAND_H

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

class ExportStudentComand : public BaseCommand {

public:
    ExportStudentComand(QModelIndex parent, QString _filename, TreeModel* _treeModel);


    ~ExportStudentComand() {};

    virtual void undo();

    virtual void redo();

private:
    TreeModel* treeModel;
    QModelIndex group;
    QString filename;
};

#endif // EXPORTSTUDENTCOMAND_H
