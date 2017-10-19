#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QString>
#include <QStringList>
#include <QTimer>
#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <QLabel>
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
    auto generate = [=] {
        int msec_left = 0;
        while (true) {
            msec_left -= 100;

            if (msec_left <= 0) {

                msec_left = (rand() % 5000) + 100;
                last10_left = msec_left;
                queue.enqueue(rand() % 100);
                updateLast10();
            }
            std::this_thread::sleep_for(100ms);
        }
    };

    std::thread thr(generate);
    thr.detach();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMainCycle()));
    timer->start(100);

    QTimer* timer2 = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimerAll()));
    timer2->start(timerTick);

    QTimer* timer3 = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimerLast10()));
    timer3->start(timerTick);
}

void MainWindow::updateMainCycle()
{
    msec_left -= 100;

    if (msec_left <= 0) {
        updateAllList();
        msec_left = 3000;
    }
}

void MainWindow::updateTimerAll()
{
     ui->timeAll->setText(QString::number(msec_left>0?msec_left:0));
}

void MainWindow::updateTimerLast10()
{
     ui->timeLast10->setText(QString::number(last10_left>0?last10_left:0));

}

void MainWindow::updateLast10()
{
    QVector<int> last10 = queue.getItems();
   // std::cout << "GENERATED" << std::endl;
    std::cout<<"LAST ";
    for(auto tt:last10){
        std::cout<<"_"<<tt;
    }
std::cout<<std::endl;
    updateList(last10, 10, ui->last10);
}

void MainWindow::updateAllList()
{
    QVector<int> allItems = queue.getItems();
    std::cout<<"ITEMS ";
    for(auto tt:allItems){
        std::cout<<"_"<<tt;
    }
    std::cout<<std::endl;
    updateList(allItems, allItems.size(), ui->allItems);
}

void MainWindow::updateList(QVector<int> values, int position, QListWidget* view)
{
    QStringList items;
    for (int i = 0; i < position and i < values.size() ; i++) {
        items.append(QString::number(values[values.size()-i-1]));
    }
    view->clear();
    view->addItems(items);
}
