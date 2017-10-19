#ifndef CHANGESTUDENT_H
#define CHANGESTUDENT_H


#include <QDialog>
#include <QTreeView>
#include "TreeModel.h"
#include <QUndoStack>

namespace Ui {
class ChangeStudent;
}

class ChangeStudent : public QDialog
{
    Q_OBJECT

public:

    explicit ChangeStudent(QTreeView *_treeView, TreeModel *_treeModel, QUndoStack *_undoStack, QWidget *parent = 0);
    ~ChangeStudent();

  // void setParams(Facade *facade, QTreeView *viewer);

private slots:
    void on_m_cancel_clicked();

    void on_m_ok_clicked();

private:
    Ui::ChangeStudent *ui;
    QTreeView *treeView;
    TreeModel *treeModel;
    QUndoStack *undoStack;

};

#endif // CHANGESTUDENT_H
