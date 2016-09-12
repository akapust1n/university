#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <structures.h>
#include "file_read.h"
#include <QtGui>
#include <conversions.h>
#include <cstring>
#include <entrypoint.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pov_null();
    sdv_null();
    btn_mas = NULL;
    txt1_mas = NULL;
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, ui->graphicsView->width(),
        ui->graphicsView->height(), this);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow() {
    uChangeData change;
    change.scene = scene;
    Apply(caDelModels, &change);
    delete ui; }

void MainWindow::set_style_button(pick a)
{
    switch (a) {
    case pick_mash: {
        ui->pushButton->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->pushButton_2->setStyleSheet(QString::fromUtf8(""));
        ui->pushButton_3->setStyleSheet(QString::fromUtf8(""));
        break;
    }
    case pick_pov: {
        ui->pushButton_2->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->pushButton->setStyleSheet(QString::fromUtf8(""));
        ui->pushButton_3->setStyleSheet(QString::fromUtf8(""));
        break;
    }
    case pick_sdvig: {
        ui->pushButton_3->setStyleSheet(QString::fromUtf8(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
            "stop: 0 #dadbde, stop: 1 #f6f7fa)"));
        ui->pushButton_2->setStyleSheet(QString::fromUtf8(""));
        ui->pushButton->setStyleSheet(QString::fromUtf8(""));
    }
    }

    return;
}

void MainWindow::on_pushButton_clicked()
{
    if (!btn_mas) {
        set_style_button(pick_mash);
        delete_other(pick_mash);
        btn_mas = new QPushButton(this);
        btn_mas->setGeometry(630, 83, 111, 19);
        btn_mas->setStyleSheet(
            QString::fromUtf8("background-color: rgb(244, 115, 255);"));
        btn_mas->show();
        btn_mas->setText("Масштабировать");
        QRegExp a1("[]{0,1}[0-9]{1,7}[.]{1}[0-9]{1,5}");
        txt1_mas = new QLineEdit(this);
        txt1_mas->setValidator((new QRegExpValidator(a1)));
        txt1_mas->setGeometry(630, 115, 60, 19);
        txt1_mas->show();
    }
    QObject::connect(btn_mas, SIGNAL(clicked()), SLOT(on_btn_mas_clicked()));

    return;
}
void MainWindow::on_btn_mas_clicked()
{
    uChangeData change;
    change.scale = txt1_mas->text().toDouble();
    change.scene = scene;
    Apply(caScale, &change);
    Apply(caDraw, &change);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (!btn_pov) {
        set_style_button(pick_pov);

        delete_other(pick_pov);
        create_pov();
        set_pov();
        QRegExp a1("[]{0,1}[0-9]{1,7}[.]{1}[0-9]{1,5}");
        txt1_pov->setValidator((new QRegExpValidator(a1)));
        txt2_pov->setValidator((new QRegExpValidator(a1)));
        txt3_pov->setValidator((new QRegExpValidator(a1)));

    }
    QObject::connect(btn_pov, SIGNAL(clicked()), SLOT(on_btn_pov_clicked()));
}
void MainWindow::on_btn_pov_clicked()
{
    sMove move;
    uChangeData change;
    // QMessageBox mbox;
    // mbox.setText("povorot");
    // mbox.exec();
    move.dx = txt1_pov->text().toDouble() / 180.0 * M_PI;
    move.dy = txt2_pov->text().toDouble() / 180.0 * M_PI;
    move.dz = txt3_pov->text().toDouble() / 180.0 * M_PI;
    change.move = move;
    change.scene = scene;
    Apply(caSetRot, &change);
    Apply(caDraw, &change);
}

void MainWindow::on_pushButton_3_clicked()
{
    if (!btn_sdv) {
        set_style_button(pick_sdvig);
        delete_other(pick_sdvig);
        create_sdv();
        set_sdv();
        QRegExp a1("[]{0,1}[0-9]{1,7}[.]{1}[0-9]{1,5}");
        txt1_sdv->setValidator((new QRegExpValidator(a1)));
        txt2_sdv->setValidator((new QRegExpValidator(a1)));
        txt3_sdv->setValidator((new QRegExpValidator(a1)));
    }
    QObject::connect(btn_sdv, SIGNAL(clicked()), SLOT(on_btn_sdv_clicked()));
}
void MainWindow::on_btn_sdv_clicked()
{
    sMove move;
    uChangeData change;
    move.dx = txt1_sdv->text().toDouble();
    move.dy = txt2_sdv->text().toDouble();
    move.dz = txt3_sdv->text().toDouble();
    change.move = move;
    change.scene = scene;
    Apply(caShift, &change);
    Apply(caDraw, &change);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, QString::fromUtf8("Открыть файл"),
        QDir::currentPath(), "txt models (*.txt)");
    uChangeData change;

    strcpy(change.filename, filename.toStdString().c_str());
    change.scene = scene;
    eCodeFile result = Apply(caLoad, &change);

    switch (result) {
    case (cfFine): {
        break;
    }
    case (cfNotFound): {
        QMessageBox mbox;
        mbox.setText("Файл не найден!");
        mbox.exec();
        break;
    }
    case (cfCorrupted): {
        QMessageBox mbox;
        mbox.setText("Файл содержит некорректные данные!");
        mbox.exec();
        break;
    }
    case (cfOutOfMemory): {
        QMessageBox mbox;
        mbox.setText("Не хватает памяти для загрузки модели!");
        mbox.exec();
        break;
    }
    default: {
        QMessageBox mbox;
        mbox.setText("Неизвестная ошибка");
        mbox.exec();
        break;
    }
    }
     Apply(caDraw, &change);
}
