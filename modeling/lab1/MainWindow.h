#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QMainWindow>
#include <QChartView>
#include <random>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    QChartView* chartViewFunc;
    QChartView* chartViewDensity;
    QChartView* chartViewFunc2;
    QChartView* chartViewDensity2;


 private:
    int factorial(int k);
    double func(double lambda, double k);
    double func2(double x, double a, double b);

    double density(double lambda, double x );
    double density2(double x , double a, double b);


    void funcGraph(QVector<double> &x, QVector<double> &y);
    void funcGraph2(QVector<double> &x, QVector<double> &y);

    void funcDensity(QVector<double> &x, QVector<double> &y);
    void funcDensity2(QVector<double> &x, QVector<double> &y);

};

#endif // MAINWINDOW_H
