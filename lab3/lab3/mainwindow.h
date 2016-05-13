#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineEdit>
#include <QMainWindow>
#include <QtWidgets>
#include "Conroller.h"
#include "BigModelManager.h"
#include <SceneManager.h>
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
    void on_scaleButton_clicked();
    void Scale_slot();
    void Open_slot();

    void on_openButton_clicked();

private:
    Controller controller;
    BigModelManager bigmodelmanager;
    SceneManager scenemanager;
    QLineEdit *x_line_edit;
    QLineEdit *y_line_edit;
    QLineEdit *z_line_edit;
    QPushButton *action_button;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
