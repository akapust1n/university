#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setStyleSheet("background : black; color : red; ;");
    ui->lcdNumber->setPalette(Qt::red);

}

MainWindow::~MainWindow()
{
    delete ui;
}
