#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QModelIndex>
#include <treemodel.h>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void itemChanged();

private slots:
    void insertChild();
    bool insertColumn();
    void insertRow();
    bool removeColumn();
    void removeRow();
    void openFile();
    void undo();
    void redo();
private:
    QString getName(int index);
    int index = 0;
    QVector<TreeModel*> models;
    QVector<TreeModel*> models_stack2;



};

#endif // MAINWINDOW_H
