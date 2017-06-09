#ifndef COMMANDS_H
#define COMMANDS_H

#include "ComandManager.h"
#include <QFile>
#include <QTreeView>
#include <QUndoCommand>
#include <QVector>
#include <memory>

class BaseCommand : public QUndoCommand {

public:
    BaseCommand(ComandManager* _comandManager);

protected:
    ComandManager* comandManager;
    QTreeView* treeView;
};

class LoadCommand : public BaseCommand {

public:
    LoadCommand(QString name, QTreeView* widget,ComandManager* _comandManager);
    ~LoadCommand() {}

    void undo() override;

    void redo() override
    {
        comandManager->loadGroupsFromJson(fileName);
        comandManager->setTreeView(treeView);
    }

private:
    QString fileName;
};

class SaveCommand : public BaseCommand {

public:
    SaveCommand(QString name, ComandManager *_comandManager);
    ~SaveCommand();

    void undo() override;

    void redo() override;

private:
    QString fileName;
};

class ChangeInfoCommand : public BaseCommand {

public:
    ChangeInfoCommand(QModelIndexList indxList, QVector<QVariant> nextData, ComandManager *_comandManager);

    ~ChangeInfoCommand();

    void undo() override;

    void redo() override;

private:
    QModelIndexList indxList;
    QVector<QVariant> prevData;
    QVector<QVariant> nextData;
};

class InsertCommand : public BaseCommand {

public:
    InsertCommand(QModelIndex parent, QVector<QVariant> insertData, ComandManager *_comandManager);
    ~InsertCommand();

    void undo() override;

    void redo() override;

private:
    QModelIndex parent;
    QVector<QVariant> insertData;
};

class RemoveCommand : public BaseCommand {

public:
    RemoveCommand(QModelIndex indx, QVector<QVector<QVariant> > backData, ComandManager *_comandManager);
    ~RemoveCommand();

    void undo() override;

    void redo() override;

private:
    QVector<QVector<QVariant> > data;
    QModelIndex index;
    QModelIndex parent;
};

#endif // COMMANDS_H
