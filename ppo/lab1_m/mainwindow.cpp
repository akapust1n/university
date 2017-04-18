#include "mainwindow.h"
#include "treemodel.h"
#include <qfiledialog.h>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);



    connect(exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

   // connect(view->selectionModel(), &QItemSelectionModel::selectionChanged,
     //       this, &MainWindow::updateActions);

    connect(insertRowAction, &QAction::triggered, this, &MainWindow::insertRow);

    connect(insertChildAction, &QAction::triggered, this, &MainWindow::insertChild);
    connect(actionOpen_File, &QAction::triggered, this, &MainWindow::openFile);
    connect(actionUndo, &QAction::triggered, this, &MainWindow::undo);
    connect(actionRedo, &QAction::triggered, this, &MainWindow::redo);



}

void MainWindow::insertChild()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }

    if (!model->insertRow(0, index))
        return;

    view->selectionModel()->setCurrentIndex(model->index(0, 0, index),
                                            QItemSelectionModel::ClearAndSelect);
}


void MainWindow::insertRow()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();

    if (!model->insertRow(index.row()+1, index.parent()))
        return;

    for (int column = 0; column < model->columnCount(index.parent()); ++column) {
        QModelIndex child = model->index(index.row()+1, column, index.parent());
        model->setData(child, QVariant("[No data]"), Qt::EditRole);
    }
}


void MainWindow::removeRow()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel *model = view->model();
    model->removeRow(index.row(), index.parent());

}

void MainWindow::openFile()
{
    QStringList headers;
    headers << tr("Groups");

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/alexey/16/university/ppo/lab1_m", tr("Json Files (*.json)"));
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    TreeModel *model = new TreeModel(headers, file.readAll(), this);
    file.close();

    view->setModel(model);
    for (int column = 0; column < model->columnCount(); ++column)
        view->resizeColumnToContents(column);

}

void MainWindow::undo()
{

}

void MainWindow::redo()
{

}


