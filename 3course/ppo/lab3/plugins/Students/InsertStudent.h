#ifndef INSERTSTUDENT_H
#define INSERTSTUDENT_H


#include <QDialog>
#include "TreeModel.h"
#include <QUndoStack>

namespace Ui {
class InsertStudent;
}

class InsertStudent : public QDialog
{
    Q_OBJECT

public:
    explicit InsertStudent(QModelIndex _index, TreeModel* _treeModel, QUndoStack* _undoStack, QWidget* parent = nullptr);
    ~InsertStudent();


private slots:
    void on_m_cancel_2_clicked();

    void on_m_ok_2_clicked();

private:
    Ui::InsertStudent *ui;
    QModelIndex m_parent;
    TreeModel *treeModel;
    QUndoStack *undoStack;
};
#endif // INSERTSTUDENT_H
