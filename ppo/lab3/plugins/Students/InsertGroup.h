#ifndef INSERTGROUP_H
#define INSERTGROUP_H

#include <QDialog>
//#include "Facade/facade.h"
#include <QModelIndex>
#include "TreeModel.h"
#include <QUndoStack>

namespace Ui {
class InsertGroup;
}

class InsertGroup : public QDialog
{
    Q_OBJECT

public:
    explicit InsertGroup(QModelIndex index,TreeModel *_treeModel,QUndoStack *_undoStack, QWidget *parent = 0);
    ~InsertGroup();

  //  void setParam(Facade *facade, QModelIndex &parent);
private slots:
    void on_m_cancel_clicked();

    void on_m_ok_clicked();

private:
    Ui::InsertGroup *ui;
    QModelIndex m_parent;
    TreeModel *treeModel;
    QUndoStack *undoStack;
    //Facade *m_facade;

};

#endif // INSERTGROUP_H
