#include <Conroller.h>
#include <ui_mainwindow.h>
void Controller::setUi(Ui::MainWindow*& temp)
{
    ui = temp;
}

new_params Controller::getParams(pick a)
{
    new_params temp;

    switch (a) {
    case (pick::pick_mash): {
        temp.M = ui->xlineEdit->text().toInt();
        break;
    }
    case (pick::pick_pov): {
        temp.fx = ui->xlineEdit->text().toInt();
        temp.fy = ui->ylineEdit->text().toInt();
        temp.fz = ui->zlineEdit->text().toInt();
        break;
    }
    case (pick::pick_sdvig): {
        temp.dx = ui->xlineEdit->text().toInt();
        temp.dy = ui->ylineEdit->text().toInt();
        temp.dz = ui->zlineEdit->text().toInt();
        break;
    }
    }
    return temp;
}
