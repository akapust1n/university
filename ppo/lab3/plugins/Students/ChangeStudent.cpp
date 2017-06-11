#include "ChangeStudent.h"
#include "ChangeComand.h"
#include "ui_changestudent.h"

ChangeStudent::ChangeStudent(QTreeView* _treeView, TreeModel* _treeModel, QUndoStack* _undoStack, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ChangeStudent)
    , treeView(_treeView)
    , treeModel(_treeModel)
    , undoStack(_undoStack)

{
    ui->setupUi(this);
    QModelIndexList list = treeView->selectionModel()->selectedIndexes();

    ui->m_surname->setText(list.at(0).data().toString());
    ui->m_name->setText(list.at(1).data().toString());
    ui->m_secondName->setText(list.at(2).data().toString());
    ui->m_raiting->setText(list.at(3).data().toString());
    ui->m_role->setText(list.at(4).data().toString());
}
ChangeStudent::~ChangeStudent()
{
    delete ui;
}

void ChangeStudent::on_m_cancel_clicked()
{
    this->close();
}

void ChangeStudent::on_m_ok_clicked()
{
    QVector<QVariant> next;
    next << ui->m_surname->text() << ui->m_name->text() << ui->m_secondName->text() << ui->m_raiting->text() << ui->m_role->text();

    ChangeCommand* changeComand = new ChangeCommand(treeView->selectionModel()->selectedIndexes(), next, treeModel);

    undoStack->push(changeComand);
    this->close();
}
