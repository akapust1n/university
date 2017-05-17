#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QListView>
#include <QMutexLocker>
#include <QStringList>
#include <QTimer>
#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std::chrono_literals;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int msec_left = 0;

    auto generate = [=] {
        int msec_left = 0;
        while (true) {
            msec_left -= 100;
            std::cout << "SECOND cycle" << std::endl;

            if (msec_left <= 0) {

                msec_left = (rand() % 5000) + 100;
                QMutexLocker locker(&mutex);
                generated = true;
            }
            std::this_thread::sleep_for(100ms);
        }
    };
    std::cout << "BEFORE THREAD" << std::endl;
    ui->allItems->update();

    std::thread thr(generate);

    thr.detach();
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMainCycle()));
    timer->start(100);
}

void MainWindow::updateMainCycle()
{
    msec_left -= 100;
    QMutexLocker locker(&mutex);
    std::cout << "main cycle" << std::endl;

    if (generated) {
        updateCurrentList();
        generated = false;
    }
    if (msec_left <= 0) {
        updateAllList();

        msec_left = (rand() % 3000) + 100;
    }
}

void MainWindow::updateCurrentList()
{

    if (queue.size() >= queueSize)
        queue.dequeue();
    queue.enqueue(rand() % 100);
    auto items = queue.getItems();

    QStringList currentListItems;
    for (int i = 0; i < 10 and i < items.size()-1; i++) {
        std::cout << QString::number(items[items.size()-i-1]).toStdString();
        currentListItems.append(QString::number(items[items.size()-i-1]));
    }
    ui->last10->clear();
    ui->last10->addItems(currentListItems);
    std::cout << "SIZE " << currentListItems.size() << std::endl;
}

void MainWindow::updateAllList()
{
    if (queue.size() >= queueSize)
        queue.dequeue();
    queue.enqueue(rand() % 100);
    auto items = queue.getItems();

    QStringList currentListItems;
    for (int i : items) {
        std::cout << QString::number(i).toStdString();
        currentListItems.append(QString::number(i));
    }
    ui->allItems->clear();
    ui->allItems->addItems(currentListItems);
    std::cout << "SIZE " << currentListItems.size() << std::endl;
}
