#include <Facade.h>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
Facade::Facade()
{
    scenemanager = new SceneManager;
    bigmodelmanager = new BigModelManager;
    controller = new Controller;
    bigmodelmanager->setContoller(controller);
}
Facade::~Facade()
{
    delete scenemanager;
    delete bigmodelmanager;
    delete controller;
}
void Facade::camera_changed()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_camera);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}

void Facade::rotated()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_pov);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}
void Facade::scaled()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_mash);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}
void Facade::shifted()
{
    try {
        bigmodelmanager->callSetSceneObjectManager(pick::pick_sdvig);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}
void Facade::open_file(string sourceName)
{

    try {
        bigmodelmanager->callDataManager(sourceName);
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
    try {
        scenemanager->drawModels();
    } catch (my_base_exception& err) {
        QMessageBox temp;
        QString tt(err.what());
        temp.setText(tt);
        temp.exec();
    }
}
QGraphicsScene* Facade::get_scene()
{
    return scenemanager->Qscene->scene;
}
void Facade::getui(Ui::MainWindow*& ui1)
{
    ui = ui1;
    controller->setUi(ui);
    scenemanager->setupUi(ui, bigmodelmanager->scene);
}
