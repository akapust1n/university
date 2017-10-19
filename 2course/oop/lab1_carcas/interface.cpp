#include "mainwindow.h"
#include <QtWidgets>

#define btns_null(type)            \
    void MainWindow::type##_null() \
    {                              \
        btn_##type = NULL;         \
        txt1_##type = NULL;        \
        txt2_##type = NULL;        \
        txt3_##type = NULL;        \
        label1_##type = NULL;      \
        label2_##type = NULL;      \
        label3_##type = NULL;      \
    }

#define delete_btns(type)            \
    void MainWindow::delete_##type() \
    {                                \
        delete btn_##type;           \
        delete txt1_##type;          \
        delete txt2_##type;          \
        delete txt3_##type;          \
        delete label1_##type;        \
        delete label2_##type;        \
        delete label3_##type;        \
    }

btns_null(sdv) btns_null(pov) delete_btns(pov) delete_btns(sdv)

    void MainWindow::delete_mas()
{
    delete btn_mas;
    delete txt1_mas;
}
void MainWindow::mas_null()
{
    btn_mas = NULL;
    txt1_mas = NULL;
}

void MainWindow::delete_other(pick a) //ну вдруг сойдет
{
    if (btn_pov and ((a == pick_mash) or (a == pick_sdvig))) {
        delete_pov();
        pov_null();
    }
    if (btn_mas and ((a == pick_sdvig) or (a == pick_pov))) {
        delete_mas();
        mas_null();
    }
    if (btn_sdv and ((a == pick_mash) or (a == pick_pov))) {
        delete_sdv();
        sdv_null();
    }

    return;
}

#define create_btns(type)                   \
    void MainWindow::create_##type()        \
    {                                       \
        btn_##type = new QPushButton(this); \
        txt1_##type = new QLineEdit(this);  \
        txt2_##type = new QLineEdit(this);  \
        txt3_##type = new QLineEdit(this);  \
        label1_##type = new QLabel(this);   \
        label2_##type = new QLabel(this);   \
        label3_##type = new QLabel(this);   \
    }

create_btns(pov) create_btns(sdv)

    void MainWindow::set_pov()
{
    btn_pov->setGeometry(630, 83, 111, 19);
    btn_pov->setStyleSheet(
        QString::fromUtf8("background-color: rgb(244, 115, 255);"));
    btn_pov->setText("Повернуть");
    btn_pov->show();
    label1_pov->setText("o X: ");
    label1_pov->setGeometry(630, 120, 20, 10);
    label1_pov->show();
    txt1_pov->setGeometry(650, 115, 40, 19);
    txt1_pov->show();
    label2_pov->setText("o Y: ");
    label2_pov->setGeometry(630, 150, 20, 10);
    label2_pov->show();
    txt2_pov->setGeometry(650, 145, 40, 19);
    txt2_pov->show();

    label3_pov->setText("o Z: ");
    label3_pov->setGeometry(630, 180, 20, 10);
    label3_pov->show();
    txt3_pov->setGeometry(650, 175, 40, 19);
    txt3_pov->show();
}
void MainWindow::set_sdv()
{
    btn_sdv->setGeometry(630, 83, 111, 19);
    btn_sdv->setStyleSheet(
        QString::fromUtf8("background-color: rgb(244, 115, 255);"));
    btn_sdv->setText("Сдвинуть");
    btn_sdv->show();
    label1_sdv->setText(" dX: ");
    label1_sdv->setGeometry(630, 120, 20, 10);
    label1_sdv->show();
    txt1_sdv->setGeometry(650, 115, 40, 19);
    txt1_sdv->show();
    label2_sdv->setText(" dY: ");
    label2_sdv->setGeometry(630, 150, 20, 10);
    label2_sdv->show();
    txt2_sdv->setGeometry(650, 145, 40, 19);
    txt2_sdv->show();

    label3_sdv->setText(" dZ: ");
    label3_sdv->setGeometry(630, 180, 20, 10);
    label3_sdv->show();
    txt3_sdv->setGeometry(650, 175, 40, 19);
    txt3_sdv->show();
}
