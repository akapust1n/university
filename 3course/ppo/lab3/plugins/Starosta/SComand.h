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

class SCommand : public BaseCommand {

public:
    SCommand(QModelIndex _index);
    ~SCommand() {}

    void undo() override;

    void redo() override;

private:

    QModelIndex index;
};
#endif
