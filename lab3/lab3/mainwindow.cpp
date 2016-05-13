#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <DataManager.h>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   QObject::connect(ui->openButton, SIGNAL(clicked()), SLOT(Open_slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scaleButton_clicked()
{
   action_button = new QPushButton;
   QObject::connect(action_button , SIGNAL(clicked()), SLOT(Scale_slot()));
}

void MainWindow::Scale_slot()
{

}

void MainWindow::Open_slot()
{

}

void MainWindow::on_openButton_clicked()
{
    string sourceName = QFileDialog::getOpenFileName(this, QString::fromUtf8("Открыть файл"),
        QDir::currentPath(), "txt models (*.txt)").toStdString();

    bigmodelmanager.callDataManager(sourceName);
}
