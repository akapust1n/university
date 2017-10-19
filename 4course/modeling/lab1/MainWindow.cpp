#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QScopedPointer>
#include <QVector>
#include <QtCharts>
#include <cmath>
#include <iostream>
#include <boost/math/special_functions/gamma.hpp>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QChart* chart{ new QChart() };

    chartViewFunc = new QChartView(chart);
    chartViewDensity = new QChartView(chart);
    chartViewFunc2 = new QChartView(chart);
    chartViewDensity2 = new QChartView(chart);

    ui->verticalLayout_2->addWidget(chartViewFunc, 0, 0);
    ui->verticalLayout->addWidget(chartViewDensity, 0, 0);

    ui->verticalLayout_3->addWidget(chartViewFunc2, 0, 0);
    ui->verticalLayout_4->addWidget(chartViewDensity2, 0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QVector<double> xFunc;
    QVector<double> yFunc;
    QVector<double> xDensity;
    QVector<double> yDensity;

    QVector<double> xFunc2;
    QVector<double> yFunc2;
    QVector<double> xDensity2;
    QVector<double> yDensity2;

    funcGraph(xFunc, yFunc);
    funcDensity(xDensity, yDensity);

    QLineSeries* seriesFunc = new QLineSeries(this);
    for (int i = 0; i < xFunc.size(); i++) {
        seriesFunc->append(xFunc[i], yFunc[i]);
    }
    QChart* chart{ new QChart() };
    chart->legend()->hide();
    chart->addSeries(seriesFunc);
    chart->createDefaultAxes();
    chartViewFunc->setChart(chart);

    QLineSeries* seriesDensity = new QLineSeries(this);
    for (int i = 0; i < xDensity.size(); i++) {
        seriesDensity->append(xDensity[i], yDensity[i]);
    }
    QChart* chart2{ new QChart() };
    chart2->legend()->hide();
    chart2->addSeries(seriesDensity);
    chart2->createDefaultAxes();
    chartViewDensity->setChart(chart2);


    funcGraph2(xFunc2, yFunc2);
    funcDensity2(xDensity2, yDensity2);

    QLineSeries* seriesFunc2 = new QLineSeries(this);
    for (int i = 0; i < xFunc2.size(); i++) {
        seriesFunc2->append(xFunc2[i], yFunc2[i]);
    }
    QChart* chart21{ new QChart() };
    chart21->legend()->hide();
    chart21->addSeries(seriesFunc2);
    chart21->createDefaultAxes();
    chartViewFunc2->setChart(chart21);

    QLineSeries* seriesDensity2 = new QLineSeries(this);
    for (int i = 0; i < xDensity2.size(); i++) {
        seriesDensity2->append(xDensity2[i], yDensity2[i]);
    }
    QChart* chart22{ new QChart() };
    chart22->legend()->hide();
    chart22->addSeries(seriesDensity2);
    chart22->createDefaultAxes();
    chartViewDensity2->setChart(chart22);
}

int MainWindow::factorial(int k)
{
    int fact = 1;
    for (int i = 1; i < k; i++) {
        fact *= i;
    }
    return fact;
}

double MainWindow::func(double lambda, double k)
{
   // std::gamma_distribution<double> distribution(k + 1, lambda);
    auto tt = boost::math::gamma_p<double, double>(k+1, lambda);
    std::cout<<tt<<std::endl;
    double result =tt / factorial(k);
    std::cout << "RESULT " << result << std::endl;
    return result;
}

double MainWindow::func2(double x, double a, double b)
{
    if (x < a)
        return 0;
    if (x >= a and x <= b)
        return ((x - a) / (b - a));
    return 1;
}

double MainWindow::density(double lambda, double x)
{
    double result = 0;
    if (x > 0) {
        result = lambda * exp(-lambda * x);
    }
    return result;
}

double MainWindow::density2(double x, double a, double b)
{
    if (x >= a and x <= b)
        return (1/(b-a));
    return 0;

}

void MainWindow::funcGraph(QVector<double>& x, QVector<double>& y)
{
    int maxK = ui->keyEdit->text().toInt();
    double lambda = ui->lambdaEdit->text().toInt();

    double funcValue = 0;

    for (int i = 0; i < maxK; i++) {
        funcValue = func(lambda, i);
        x.push_back(i);
        y.push_back(funcValue);
    }
}

void MainWindow::funcGraph2(QVector<double>& x, QVector<double>& y)
{
    double a = ui->aEdit->text().toDouble();
    double b = ui->bEdit->text().toDouble();
    double maxX = ui->maxX->text().toDouble();
    double step = ui->steps->text().toDouble();
    double funcValue = 0;
    for (int i = 0; i < maxX; i += step) {
        funcValue = func2(i, a, b);
        x.push_back(i);
        y.push_back(funcValue);
    }
}
void MainWindow::funcDensity(QVector<double>& x, QVector<double>& y)
{
    double maxX = ui->maxX->text().toDouble();
    double step = maxX / ui->maxX->text().toDouble();

    double lambda = ui->lambdaEdit->text().toInt();

    double funcValue = 0;

    for (double i = 0; i < maxX; i += step) {
        funcValue = density(lambda, i);
        x.push_back(i);
        y.push_back(funcValue);
    }
}

void MainWindow::funcDensity2(QVector<double>& x, QVector<double>& y)
{

    double a = ui->aEdit->text().toDouble();
    double b = ui->bEdit->text().toDouble();
    double maxX = ui->maxX->text().toDouble();
    double step = ui->steps->text().toDouble();

    double funcValue = 0;

    for (double i = 0; i < maxX; i += step) {
        funcValue = density2(i,a,b);
        x.push_back(i);
        y.push_back(funcValue);
    }
}
