#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QValidator>
#include <QSharedPointer>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSharedPointer<QDoubleValidator> validator;
    validator.reset(new QDoubleValidator(0, 100, 10));
   // QLocale locale(QLocale::English);
  //  validator->setLocale(locale);
    ui->start->setValidator(validator.data()); //dont work(
    ui->end->setValidator(validator.data());
    ui->step->setValidator(validator.data());
    ui->table->setColumnCount(9);
    QStringList labels;
    labels.append("x");
    labels.append("Pickar 1");
    labels.append("Pickar 2");
    labels.append("Pickar 3");
    labels.append("Pickar 4");
    labels.append("R–Kutta 0.5");
    labels.append("R–Kutta 1");
    labels.append("Explicit");
    labels.append("NotExplicit");







   ui->table->setHorizontalHeaderLabels(labels);

    m_info.reset(new info);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_info->end = ui->end->text().toDouble();
    m_info->start = ui->start->text().toDouble();
    m_info->step = ui->step->text().toDouble();
    qDebug() <<" stop1";

    qint32 rows = ((m_info->end - m_info->start)) / m_info->step +1.5;
    qDebug() <<" stop1.1";

    ui->table->setRowCount(rows);
    qDebug() <<" stop1.2";



    methods[1].reset(new Pickar1(m_info));
  // setup up x values into table
    qDebug() <<" stop2";

    int i = 0;
    auto x_values = methods[1]->getXvalues();
    for(double a : x_values){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        qDebug()<<qreal(a);

        ui->table->setItem(i,0, item);
                i++;

    }
    qDebug() <<" stop3";

    i = 0;
    auto array = methods[1]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i,1, item);
                i++;
      //  delete item;
    }

    i = 0;
    methods[2].reset(new Pickar2(m_info));

    array = methods[2]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 2, item);
                i++;
    }

    i = 0;
    methods[3].reset(new Pickar3(m_info));

    array = methods[3]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 3, item);
         i++;
    }

    i = 0;
    methods[4].reset(new Pickar4(m_info));

    array = methods[4]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 4, item);
         i++;
    }

    i = 0;
    methods[5].reset(new RungeKutt(m_info, 0.5));

    array = methods[5]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 5, item);
         i++;
    }

    i = 0;
    methods[6].reset(new RungeKutt(m_info, 1));

    array = methods[6]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 6, item);
         i++;
    }

    i = 0;
    methods[7].reset(new ExplicitMethod(m_info));

    array = methods[7]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 7, item);
         i++;
    }

    i = 0;
    methods[8].reset(new NotExplicitMethod(m_info));

    array = methods[8]->getValues();
    for(double a : array ){

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->table->setItem(i , 8, item);
         i++;
    }



}
