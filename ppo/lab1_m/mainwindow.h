#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QModelIndex>
#include <QUndoStack>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void updateActions();

private slots:
    void insertChild();
    void insertRow();
    bool removeColumn();
    void removeRow();
    void openFile();
    void undo();
    void redo();
private:
    QUndoStack undostack;

};

#endif // MAINWINDOW_H
