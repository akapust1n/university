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

class LoadTeachersCommand : public BaseCommand {

public:
    LoadTeachersCommand(QString name, QTreeView* widget);
    ~LoadTeachersCommand() {}

    void undo() override;

    void redo() override;
    TreeModel *getTreeModel();


private:
    void loadsubjectsFromJson(QString fileName);

    TreeModel* loadFromJson(QString filename);
    // loadStudents
    void loadTeachers(QFile& FileLoader, TreeModel *_treeModel);
    QStringList getStudentInfo(QJsonObject& json);
    void insertTeachersToModel(QStringList studentInfo, QString subjectName, TreeModel *_treeModel);
    bool insertsubject(QString subjectName, TreeModel *_treeModel);

private:
    QString fileName;
    TreeModel *treeModel;
};
#endif
