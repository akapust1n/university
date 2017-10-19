#ifndef SAVEFILEAS_H
#define SAVEFILEAS_H

#include <QDialog>
#include <QModelIndex>
#include "TreeModel.h"
#include <QUndoStack>

namespace Ui {
class saveFile;
}

class SaveFileAs : public QDialog
{
    Q_OBJECT

public:
    explicit SaveFileAs(QModelIndex index,TreeModel *_treeModel,QUndoStack *_undoStack, QWidget *parent = 0);
    ~SaveFileAs();

private slots:
    void on_m_cancel_clicked();

    void on_m_ok_clicked();

private:
    Ui::saveFile *ui;
    QModelIndex m_parent;
    TreeModel *treeModel;
    QUndoStack *undoStack;

};



#endif // SAVEFILEAS_H
