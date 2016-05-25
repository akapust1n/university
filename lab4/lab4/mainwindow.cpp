#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPalette>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setStyleSheet("background : black; color : red; ;");
    ui->lcdNumber->setPalette(Qt::red);

    ui->lift_floor_box->hide();
    connect(&lft, SIGNAL(st_changed(state_lift)), this, SLOT(change_lift_st(state_lift)));
    connect(&lft, SIGNAL(show_lift()), this, SLOT(show_el()));
    connect(&lft, SIGNAL(hide_lift()), this, SLOT(hide_el()));
    connect(&lft, SIGNAL(floor_changed(int)), this, SLOT(floor_changed(int)));
    connect(this, SIGNAL(floor_button_pushed(int)), &lft, SLOT(floor_but(int)));
    connect(this, SIGNAL(lift_button_pushed(int)), &lft, SLOT(lift_but(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::floor_changed(int a)
{
    ui->lcdNumber->display(a);
}
void MainWindow::show_el()
{
    ui->lift_floor_box->show();
}
void MainWindow::hide_el()
{
    ui->lift_floor_box->hide();
}
void MainWindow::change_lift_st(state_lift st_l)
{
    QTime time;
    time.start();
    for (; time.elapsed() < 1000;) {
        qApp->processEvents();
    }
    switch (st_l) {
    case (state_lift::doors_closing):
        ui->lift_state->setText("doors closing");
        break;
    case state_lift::doors_opening:
        ui->lift_state->setText("doors opening");
        break;
    case state_lift::doors_opened:
        ui->lift_state->setText("doors opened");
        break;
    case state_lift::go:
        ui->lift_state->setText("moving");
        break;
    case state_lift::wait:
        ui->lift_state->setText("waiting");
        break;
    case state_lift::minor_wait:
        ui->lift_state->setText("minor_wait");
        break;
    }
}

void MainWindow::on_floor1BTN_clicked()
{

    QMessageBox tt;
    tt.setText("lol");
    tt.exec();
    emit floor_button_pushed(1);
}

void MainWindow::on_floor2BTN_clicked()
{
    floor_button_pushed(2);
}

void MainWindow::on_floor3BTN_clicked()
{
    floor_button_pushed(3);
}

void MainWindow::on_floor4BTN_clicked()
{
    floor_button_pushed(4);
}

void MainWindow::on_floor5BTN_clicked()
{
    floor_button_pushed(5);
}

void MainWindow::on_floor6BTN_clicked()
{
    floor_button_pushed(6);
}

void MainWindow::on_floor7BTN_clicked()
{
    floor_button_pushed(7);
}
