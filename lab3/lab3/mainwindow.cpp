#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <DataManager.h>

#include <string>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox_2->setEnabled(false);
    facade = new Facade;
    facade->getui(ui);
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
        ui->cameraButton->setStyleSheet(QString::fromUtf8(""));
        break;
    }
    case pick::pick_pov: {
        ui->ugolButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->shiftButton->setStyleSheet(QString::fromUtf8(""));
        ui->scaleButton->setStyleSheet(QString::fromUtf8(""));
        ui->cameraButton->setStyleSheet(QString::fromUtf8(""));
        break;
    }
    case pick::pick_sdvig: {
        ui->shiftButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->ugolButton->setStyleSheet(QString::fromUtf8(""));
        ui->scaleButton->setStyleSheet(QString::fromUtf8(""));
        ui->cameraButton->setStyleSheet(QString::fromUtf8(""));

        break;
    }
    case pick::pick_camera: {
        ui->cameraButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->ugolButton->setStyleSheet(QString::fromUtf8(""));
        ui->scaleButton->setStyleSheet(QString::fromUtf8(""));
        ui->shiftButton->setStyleSheet(QString::fromUtf8(""));


    }
    }

    return;
}
void MainWindow::on_scaleButton_clicked()
{

    set_style_button(pick::pick_mash);
    QObject::disconnect(m_connection);

    m_connection = QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Scale_slot()));
    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Масштаб");
    ui->xLabel->setText("Scale");
    ui->ylineEdit->setEnabled(false);
    ui->zlineEdit->setEnabled(false);
}

void MainWindow::Scale_slot()
{
    facade->scaled();
}

void MainWindow::Shift_slot()
{
    facade->shifted();
}

void MainWindow::Rotate_slot()
{
    facade->rotated();
}

void MainWindow::on_openButton_clicked()
{
    string sourceName = QFileDialog::getOpenFileName(this, QString::fromUtf8("Открыть файл"),
                            QDir::currentPath(), "txt models (*.txt)")
                            .toStdString();
    facade->open_file(sourceName);

    ui->graphicsView->setScene(facade->get_scene());
    ui->graphicsView->show();
}

void MainWindow::on_shiftButton_clicked()
{

    set_style_button(pick::pick_sdvig);
    QObject::disconnect(m_connection);
    m_connection = QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Shift_slot()));

    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Сдвиг");
    ui->xLabel->setText("x");
    ui->ylineEdit->setEnabled(true);
    ui->zlineEdit->setEnabled(true);
}

void MainWindow::on_ugolButton_clicked()
{

    set_style_button(pick::pick_pov);
    QObject::disconnect(m_connection);

    m_connection = QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Rotate_slot()));
    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Поворот");
    ui->xLabel->setText("x");
    ui->ylineEdit->setEnabled(true);
    ui->zlineEdit->setEnabled(true);
}

void MainWindow::on_doButton_clicked()
{
}
void MainWindow::Camera_slot()
{
    facade->camera_changed();
}

void MainWindow::on_cameraButton_clicked()
{
    set_style_button(pick::pick_camera);
    QObject::disconnect(m_connection);
    m_connection = QObject::connect(ui->doButton, SIGNAL(clicked()), SLOT(Camera_slot()));

    ui->groupBox_2->setEnabled(true);
    ui->doButton->setText("Сменить");
    ui->xLabel->setText("x");
    ui->xlineEdit->setText("10");
    ui->ylineEdit->setText("10");
    ui->zlineEdit->setText("10");
    ui->ylineEdit->setEnabled(true);
    ui->zlineEdit->setEnabled(true);
}
