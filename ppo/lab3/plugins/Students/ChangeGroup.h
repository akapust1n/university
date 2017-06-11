#ifndef CHANGEGROUP_H
#define CHANGEGROUP_H

#include <QDialog>
#include <QTreeView>
#include <QUndoStack>
#include "TreeModel.h"

namespace Ui {
class ChangeGroup;
}

class ChangeGroup : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeGroup(QTreeView *_treeView, QString _name, TreeModel *_treeModel, QUndoStack *_undoStack, QWidget *parent = nullptr);
    ~ChangeGroup();


private slots:
    void on_m_cancel_clicked();

    void on_m_ok_clicked();

private:
    Ui::ChangeGroup *ui;
    QString m_name;
    QTreeView *treeView;
    QUndoStack *undoStack;
    TreeModel *treeModel;
};
#endif // CHANGEGROUP_H
