#include "mainwindow.h"
#include "treemodel.h"
#include <QFile>
#include <QFileDialog>
#include <QTreeView>
#include <QTreeWidget>
#include <iostream>
#include <QMessageBox>
#include "groupinfo.h"

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
    connect(actionUndo, &QAction::triggered, this, &MainWindow::undo);
    connect(actionRedo, &QAction::triggered, this, &MainWindow::redo);


    QStringList headers;
    headers << tr("Groups");

    models.push_back(new TreeModel(headers, " "));
    view->setModel(models[0]);
    //view->model->d

    connect(view->model(), &QAbstractItemModel::layoutChanged,
        this, &MainWindow::itemChanged);
}

void MainWindow::itemChanged()
{
    std::cout << "ITEM CHANGED" << std::endl;
    //в стеке пустой рут, один файлоначальный итем, один измененный итем
    //добавляем ещё один измененный итем
    auto temp = models.last()->getCopy();
    models.push_back(temp);
    view->setModel(models.last());
    view->update();
    index = models.size() - 2;
    connect(view->model(), &QAbstractItemModel::dataChanged,
        this, &MainWindow::itemChanged);
}

void MainWindow::insertChild()
{
    QModelIndex index = view->selectionModel()->currentIndex();
    std::cout << "INSERT CHILD " << index.data(Qt::EditRole).toString().toStdString() << std::endl;
    QAbstractItemModel* model = view->model();
    //if (index.parent().internalPointer())
    //  return;
    if (model->columnCount(index) == 0) {
        if (!model->insertColumn(0, index))
            return;
    }
    std::cout << "befor insert row" << std::endl;
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
    view->update();
}

bool MainWindow::insertColumn()
{
    QAbstractItemModel* model = view->model();
    int column = view->selectionModel()->currentIndex().column();

    // Insert a column in the parent item.
    bool changed = model->insertColumn(column + 1);
    //if (changed)
    //   model->setHeaderData(column + 1, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);

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
        models.push_back(new TreeModel(headers, file.readAll()));
        int size = models.size();
        models.push_back(models[size - 1]->getCopy()); //одна модель исходная, другая изменяемая

        file.close();

        view->setModel(models.last());
        view->update();
        for (int column = 0; column < models.last()->columnCount(); ++column)
            view->resizeColumnToContents(column);
        connect(view->model(), &QAbstractItemModel::dataChanged,
            this, &MainWindow::itemChanged);
        index = models.size() - 2;
    }
}

void MainWindow::undo()
{
    //if(index ==3)
    //    index--;
    index -= 1;
    if (index < 0)
        index = 0;
    std::cout << "UNDO CALLED " <<index<< std::endl;

    view->setModel(models[index]);
    connect(view->model(), &QAbstractItemModel::dataChanged,
        this, &MainWindow::itemChanged);
    view->update();
    connect(view->model(), &QAbstractItemModel::dataChanged,
        this, &MainWindow::itemChanged);
}

void MainWindow::redo()
{
    index += 1;
    std::cout << "REDO CALLED " <<index << std::endl;

    if (index > models.size()-2)
        index =  models.size()-2;
    if(index<0)
        index = 0;
    view->setModel(models[index]);
    view->update();
}

QString MainWindow::getName(int index)
{
    switch (index) {
    case 0:
        return "Имя";
    case 1:
        return "Отчество";
    case 2:
        return "Рейтинг";
    case 3:
        return "Роль";
    default:
        "No data";
    }
}

void MainWindow::on_actionOpen_Card_triggered()
{
   if( view->selectionModel()->currentIndex().parent().isValid()){
       QMessageBox msgBox;
       msgBox.setWindowTitle("Информация о группе");
       msgBox.setText("Это не группа");
       msgBox.exec();
       return;
}
       else{
       GroupInfo groupInfo(view->model());
       QString result;
       std::cout<<"GRP"<<view->selectionModel()->currentIndex().data(1).toString().toStdString()<<std::endl;
       std::cout<<"GRP"<<view->selectionModel()->currentIndex().data(0).toString().toStdString()<<std::endl;

                  //result = groupInfo.getGroupInfo(view->selectionModel()->currentIndex().data(1).toString());
       QMessageBox msgBox;
       msgBox.setWindowTitle("Информация о группе");
       msgBox.setText("Это  группа");
       msgBox.exec();
       return;

   };

//GroupInfo groupInfo;
std::cout<<"actionOpenCard"<<std::endl;


}
