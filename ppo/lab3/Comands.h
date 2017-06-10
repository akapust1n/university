#ifndef COMMANDS_H
#define COMMANDS_H

#include <QFile>
#include <QTreeView>
#include <QUndoCommand>
#include <QVector>
#include <memory>
#include <iostream>

class BaseCommand : public QUndoCommand {

public:
    BaseCommand();
protected:
    QTreeView* treeView;
};

//class LoadStudentsCommand : public BaseCommand {

//public:
//    LoadStudentsCommand(QString name, QTreeView* widget)
//        : fileName(name)
//    {
//        std::cout<<"load comand created"<<std::endl;
//        treeView = widget;
//    }
//    ~LoadStudentsCommand() {}

//    void undo() override
//    {
//        comandManager->clearStudents();
//    }

//    void redo() override
//    {
//        comandManager->loadGroupsFromJson(fileName);
//        comandManager->setTreeView(treeView);
//    }

//private:
//    QString fileName;
//};

//class SaveCommand : public BaseCommand {

//public:
//    SaveCommand(QString name);
//    ~SaveCommand();

//    void undo() override;

//    void redo() override;

//private:
//    QString fileName;
//};

//class ChangeInfoCommand : public BaseCommand {

//public:
//    ChangeInfoCommand(QModelIndexList indxList, QVector<QVariant> nextData);

//    ~ChangeInfoCommand();

//    void undo() override;

//    void redo() override;

//private:
//    QModelIndexList indxList;
//    QVector<QVariant> prevData;
//    QVector<QVariant> nextData;
//};

//class InsertCommand : public BaseCommand {

//public:
//    InsertCommand(QModelIndex parent, QVector<QVariant> insertData);
//    ~InsertCommand();

//    void undo() override;

//    void redo() override;

//private:
//    QModelIndex parent;
//    QVector<QVariant> insertData;
//};

//class RemoveCommand : public BaseCommand {

//public:
//    RemoveCommand(QModelIndex indx, QVector<QVector<QVariant> > backData);
//    ~RemoveCommand();

//    void undo() override;

//    void redo() override;

//private:
//    QVector<QVector<QVariant> > data;
//    QModelIndex index;
//    QModelIndex parent;
//};

#endif // COMMANDS_H
