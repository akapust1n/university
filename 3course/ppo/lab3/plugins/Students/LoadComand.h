#ifndef SCOMAND_H
#define SCOMAND_H
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

class LoadStudentsCommand : public BaseCommand {

public:
    LoadStudentsCommand(QString name, QTreeView* widget);
    ~LoadStudentsCommand() {}

    void undo() override;

    void redo() override;
    TreeModel *getTreeModel();


private:
    void loadGroupsFromJson(QString fileName);

    TreeModel* loadFromJson(QString filename);
    // loadStudents
    void loadStudents(QFile& FileLoader, TreeModel *_treeModel);
    QStringList getStudentInfo(QJsonObject& json);
    void insertStudentToModel(QStringList studentInfo, QString groupName, TreeModel *_treeModel);
    bool insertGroup(QString groupName, TreeModel *_treeModel);

private:
    QString fileName;
    TreeModel *treeModel;
};
#endif
