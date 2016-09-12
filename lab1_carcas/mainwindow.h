#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtWidgets>
#include <QtGui>
enum pick { pick_mash, pick_pov, pick_sdvig};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton *btn_pov;
    QLineEdit *txt1_pov;
    QLineEdit *txt2_pov;
    QLineEdit *txt3_pov;
    QLabel *label1_pov;
    QLabel *label2_pov;
    QLabel *label3_pov;

    QPushButton *btn_sdv;
    QLineEdit *txt1_sdv;
    QLineEdit *txt2_sdv;
    QLineEdit *txt3_sdv;
    QLabel *label1_sdv;
    QLabel *label2_sdv;
    QLabel *label3_sdv;

    QPushButton *btn_mas;
    QLineEdit *txt1_mas;
    QGraphicsScene *scene;
    void delete_other(pick a);
    void pov_null();
    void delete_pov();
    void delete_sdv();
    void sdv_null();
    void delete_mas();
    void mas_null();
    void create_pov();
    void set_pov();
    void create_sdv();
    void set_sdv();
    void set_style_button(pick a);

private slots:
    void  on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_btn_pov_clicked();
    void on_btn_mas_clicked();
    void on_btn_sdv_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
