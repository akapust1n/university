#include "ChangeGroup.h"
#include "ui_changegroup.h"
#include "ChangeComand.h"


ChangeGroup::ChangeGroup(QTreeView *_treeView, QString _name, TreeModel *_treeModel,QUndoStack *_undoStack,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeGroup),
    treeView(_treeView),
    m_name(_name),
    undoStack(_undoStack),
    treeModel(_treeModel)
{
    ui->setupUi(this);
    ui->m_groupName->setText(m_name);

}


ChangeGroup::~ChangeGroup()
{
    delete ui;
}


void ChangeGroup::on_m_cancel_clicked()
{
    this->close();
}

void ChangeGroup::on_m_ok_clicked()
{
    QVector<QVariant> next;
    next << ui->m_groupName->text() << "" << "" << "" << "";

    ChangeCommand *changeComand= new ChangeCommand(treeView->selectionModel()->selectedIndexes(), next, treeModel);
    undoStack->push(changeComand);

    this->close();
}
