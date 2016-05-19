#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <DataManager.h>
#include <my_exception.h>
#include <string>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->groupBox_2->setEnabled(false);
    scenemanager = new SceneManager;
    bigmodelmanager = new BigModelManager;
    controller = new Controller;
    bigmodelmanager->setContoller(controller);
    controller->setUi(ui);
    scenemanager->setupUi(ui, bigmodelmanager->scene);
}
void MainWindow::clearold(QString text)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::set_style_button(pick a)
{
    switch (a) {
    case pick::pick_mash: {
        ui->scaleButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->ugolButton->setStyleSheet(QString::fromUtf8(""));
        ui->shiftButton->setStyleSheet(QString::fromUtf8(""));
        break;
    }
    case pick::pick_pov: {
        ui->ugolButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->shiftButton->setStyleSheet(QString::fromUtf8(""));
        ui->scaleButton->setStyleSheet(QString::fromUtf8(""));
        break;
    }
    case pick::pick_sdvig: {
        ui->shiftButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->ugolButton->setStyleSheet(QString::fromUtf8(""));
        ui->scaleButton->setStyleSheet(QString::fromUtf8(""));
    }
    }

    return;
}
void MainWindow::on_scaleButton_clicked()
{

    set_style_button(pick::pick_mash);
    QObject::disconnect(ui->doButton, SLOT(Open_slot()));
    QObject::disconnect(ui->doButton, SLOT(Shift_slot()));
    QObject::disconnect(ui->doButton, SLOT(Rotate_slot()));

    QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Scale_slot()));
    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Масштаб");
    ui->xLabel->setText("Scale");
    ui->ylineEdit->setEnabled(false);
    ui->zlineEdit->setEnabled(false);
}

void MainWindow::Scale_slot()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_mash);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}

void MainWindow::Shift_slot()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_sdvig);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}

void MainWindow::Rotate_slot()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_sdvig);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}

void MainWindow::on_openButton_clicked()
{
    string sourceName = QFileDialog::getOpenFileName(this, QString::fromUtf8("Открыть файл"),
                            QDir::currentPath(), "txt models (*.txt)")
                            .toStdString();
    try {
        bigmodelmanager->callDataManager(sourceName);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    scenemanager->drawModels();
    ui->graphicsView->setScene(scenemanager->Qscene->scene);
    ui->graphicsView->show();
}

void MainWindow::on_shiftButton_clicked()
{

    set_style_button(pick::pick_sdvig);
    QObject::disconnect(ui->doButton, SLOT(Open_slot()));
    QObject::disconnect(ui->doButton, SLOT(Scale_slot()));
    QObject::disconnect(ui->doButton, SLOT(Rotate_slot()));

    QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Shift_slot()));
    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Сдвиг");
    ui->xLabel->setText("x");
    ui->ylineEdit->setEnabled(true);
    ui->zlineEdit->setEnabled(true);
}

void MainWindow::on_ugolButton_clicked()
{

    set_style_button(pick::pick_pov);
    QObject::disconnect(ui->doButton, SLOT(Open_slot()));
    QObject::disconnect(ui->doButton, SLOT(Scale_slot()));
    QObject::disconnect(ui->doButton, SLOT(Shift_slot()));

    QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Rotate_slot()));
    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Поворот");
    ui->xLabel->setText("x");
    ui->ylineEdit->setEnabled(true);
    ui->zlineEdit->setEnabled(true);
}

void MainWindow::on_doButton_clicked()
{
}
