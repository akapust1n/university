#include "InsertStudent.h"
#include "InsertComand.h"

#include "ui_insertstudent.h"

InsertStudent::InsertStudent(QModelIndex _index, TreeModel* _treeModel, QUndoStack* _undoStack, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::InsertStudent)
    , m_parent(_index)
    , treeModel(_treeModel)
    , undoStack(_undoStack)
{
    ui->setupUi(this);
}

InsertStudent::~InsertStudent()
{
    delete ui;
}

void InsertStudent::on_m_cancel_2_clicked()
{
    this->close();
}

void InsertStudent::on_m_ok_2_clicked()
{
    QVector<QVariant> insertData;
    insertData << ui->m_surname_2->text() << ui->m_name_2->text() << ui->m_secondName_2->text() << ui->m_raiting_2->text() << ui->m_role_2->text();
    InsertCommand* insertComand = new InsertCommand(m_parent, insertData, treeModel);

    // m_facade->getCommand(insrtCmd);
    this->close();
    undoStack->push(insertComand);
}
