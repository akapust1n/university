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
    void selectionChanged();
    void on_actionOpen_Card_triggered();
    void on_actionSave_As_triggered();

    
private:
    QString getName(int index);
    int index = 0;
    QVector<TreeModel*> models;
    QModelIndexList indexes;
private:
    void updateConnects();





};

#endif // MAINWINDOW_H
