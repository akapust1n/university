#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <lift.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    lift lft;
signals:
    void floor_button_pushed(int);
    void lift_button_pushed(int);
public slots:
    void hide_el();
    void show_el();
    void floor_changed(int);
    void change_lift_st(state_lift);
private slots:
    void on_floor1BTN_clicked();
    void on_floor2BTN_clicked();
    void on_floor3BTN_clicked();
    void on_floor4BTN_clicked();
    void on_floor5BTN_clicked();
    void on_floor6BTN_clicked();
    void on_floor7BTN_clicked();
    void on_floor1BTN_2_clicked();
    void on_floor2BTN_2_clicked();
    void on_floor3BTN_2_clicked();
    void on_floor4BTN_2_clicked();
    void on_floor5BTN_2_clicked();
    void on_floor6BTN_2_clicked();
    void on_floor7BTN_2_clicked();
};

#endif // MAINWINDOW_H
