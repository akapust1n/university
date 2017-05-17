#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <Queue.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void updateMainCycle();


private:
    Ui::MainWindow *ui;
    QMutex mutex;
    Queue queue;
    bool generated = false;
    void updateCurrentList();
    void updateAllList();
    int queueSize = 50;
    int msec_left = 0;
};

#endif // MAINWINDOW_H
