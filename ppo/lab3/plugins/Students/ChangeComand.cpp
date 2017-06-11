#include "ChangeComand.h"



ChangeCommand::ChangeCommand(QModelIndexList indxList, QVector<QVariant> nextData, TreeModel *_treeModel)
    : treeModel(_treeModel)
    , m_indxList(indxList)
    , m_nextData(nextData)
{

    foreach (QModelIndex indx, indxList) {
        m_prevData << indx.data().toString();
    }
}

ChangeCommand::~ChangeCommand() {}

void ChangeCommand::undo()
{
    for (int i = 0; i < m_indxList.size(); i++)
        treeModel->setData(m_indxList.at(i), m_nextData.at(i));
}

void ChangeCommand::redo()
{
    for (int i = 0; i < m_indxList.size(); i++)
        treeModel->setData(m_indxList.at(i), m_nextData.at(i));
}
