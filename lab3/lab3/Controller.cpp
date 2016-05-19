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
        temp.M = ui->xlineEdit->text().toDouble();
        break;
    }
    case (pick::pick_pov): {
        temp.fx = ui->xlineEdit->text() == "" ? 0 : ui->xlineEdit->text().toDouble();
        temp.fy = ui->ylineEdit->text() == "" ? 0 : ui->ylineEdit->text().toDouble();
        temp.fz = ui->zlineEdit->text() == "" ? 0 : ui->zlineEdit->text().toDouble();
        break;
    }
    case (pick::pick_sdvig): {
        temp.dx = ui->xlineEdit->text().toDouble();
        temp.dy = ui->ylineEdit->text().toDouble();
        temp.dz = ui->zlineEdit->text().toDouble();
        break;
    }
    }
    return temp;
}
