#ifndef CHANGECOMAND_H
#define CHANGECOMAND_H

#include "TreeModel.h"

#include "Comands.h"
#include <QByteArray>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>
#include <QTreeView>
#include <QUndoCommand>
#include <QVector>
class ChangeCommand : public BaseCommand {
private:
    QModelIndexList m_indxList;
    QVector<QVariant> m_prevData;
    QVector<QVariant> m_nextData;

public:
    ChangeCommand(QModelIndexList indxList, QVector<QVariant> nextData,
        TreeModel* _treeModel);

    ~ChangeCommand();

    virtual void undo();

    virtual void redo();

private:
    TreeModel* treeModel;
};

#endif // CHANGECOMAND_H
