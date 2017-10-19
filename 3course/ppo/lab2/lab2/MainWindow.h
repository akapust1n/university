#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QueueThreadSafe.h>
#include <mutex>
#include <QStringList>
#include <QVector>
#include <QListWidget>

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
    void updateTimerAll();
    void updateTimerLast10();


private:
    Ui::MainWindow *ui;
    QueueThreadSafe queue;
    int msec_left = 0;
    int last10_left = 0;

    int const timerTick = 60;
private:
    void updateLast10();
    void updateAllList();
    void updateList(QVector<int> values, int position, QListWidget *view);



};

#endif // MAINWINDOW_H
