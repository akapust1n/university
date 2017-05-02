#include "mainwindow.h"
#include "treemodel.h"
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi(this);

    connect(exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    connect(insertRowAction, &QAction::triggered, this, &MainWindow::insertRow);
    connect(insertColumnAction, &QAction::triggered, this, &MainWindow::insertColumn);
    connect(removeRowAction, &QAction::triggered, this, &MainWindow::removeRow);
    connect(removeColumnAction, &QAction::triggered, this, &MainWindow::removeColumn);
    connect(insertChildAction, &QAction::triggered, this, &MainWindow::insertChild);
    connect(actionOpen_File, &QAction::triggered, this, &MainWindow::openFile);

}

void MainWindow::insertChild()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel* model = view->model();
    if (index.parent().internalPointer())
        return;
    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }

    if (!model->insertRow(0, index))
        return;

    for (int column = 0; column < model->columnCount(index); ++column) {
        QModelIndex child = model->index(0, column, index);
        model->setData(child, QVariant("[No data]"), Qt::EditRole);
        if (!model->headerData(column, Qt::Horizontal).isValid())
            model->setHeaderData(column, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);
    }

    view->selectionModel()->setCurrentIndex(model->index(0, 0, index),
        QItemSelectionModel::ClearAndSelect);
}

bool MainWindow::insertColumn()
{
    QAbstractItemModel* model = view->model();
    int column = view->selectionModel()->currentIndex().column();

    // Insert a column in the parent item.
    bool changed = model->insertColumn(column + 1);
    if (changed)
        model->setHeaderData(column + 1, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);


    return changed;
}

void MainWindow::insertRow()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel* model = view->model();

    if (!model->insertRow(index.row() + 1, index.parent()))
        return;


    for (int column = 0; column < model->columnCount(index.parent()); ++column) {
        QModelIndex child = model->index(index.row() + 1, column, index.parent());
        model->setData(child, QVariant("[No data]"), Qt::EditRole);
    }
}

bool MainWindow::removeColumn()
{
    QAbstractItemModel* model = view->model();
    int column = view->selectionModel()->currentIndex().column();

    // Insert columns in each child of the parent item.
    bool changed = model->removeColumn(column);


    return changed;
}

void MainWindow::removeRow()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    QAbstractItemModel* model = view->model();
    model->removeRow(index.row(), index.parent());
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/alexey/16/university/ppo/lab1_m", tr("Json Files (*.json)"));
    if (!fileName.isNull()) {
        QStringList headers;
        headers << tr("Groups");

        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        TreeModel* model = new TreeModel(headers, file.readAll());
        file.close();

        view->setModel(model);
        for (int column = 0; column < model->columnCount(); ++column)
            view->resizeColumnToContents(column);
    }
}

