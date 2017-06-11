#include "InsertComand.h"

InsertCommand::InsertCommand(QModelIndex parent, QVector<QVariant> insertData, TreeModel* _treeModel)
    : m_parent(parent)
    , m_insertData(insertData)
    , treeModel(_treeModel)
{
}

InsertCommand::~InsertCommand() {}

void InsertCommand::undo()
{
    int row = -1;
    do {
        row++;
    } while (m_parent.child(row + 1, 0).isValid());
    QModelIndex indx = m_parent.child(row, 0);
    treeModel->removeRows(indx.row(), 1, indx.parent());
}

void InsertCommand::redo()
{
    treeModel->insertRows(treeModel->rowCount(m_parent), 1, m_parent);

  for (int i = 0; i < m_insertData.size(); i++)
       treeModel->setData(m_parent.child(treeModel->rowCount(m_parent) - 1, i), m_insertData.at(i));
}
