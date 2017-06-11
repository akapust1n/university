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



#endif // COMMANDS_H
