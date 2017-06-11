#include "InsertGroup.h"
#include "InsertComand.h"
#include "TreeModel.h"

#include "ui_insertgroup.h"

InsertGroup::InsertGroup(QModelIndex index, TreeModel* _treeModel, QUndoStack* _undoStack, QWidget* parent)
    : m_parent(index)
    , QDialog(parent)
    , ui(new Ui::InsertGroup)
    , treeModel(_treeModel)
    , undoStack(_undoStack)
{
    ui->setupUi(this);
}

InsertGroup::~InsertGroup()
{
    delete ui;
}

//void InsertGroup::setParam(Facade *facade, QModelIndex &parent)
//{
//    m_parent = parent;
// //   m_facade = facade;
//}

void InsertGroup::on_m_cancel_clicked()
{
    this->close();
}

void InsertGroup::on_m_ok_clicked()
{
    QVector<QVariant> insertData;
    insertData << ui->m_groupName->text() << ""
               << ""
               << ""
               << "";
    InsertCommand* insertComand= new InsertCommand(m_parent, insertData, treeModel);

    // m_facade->getCommand(insrtCmd);
    this->close();
    undoStack->push(insertComand);
}
