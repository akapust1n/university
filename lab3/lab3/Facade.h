#ifndef FACADE_H
#define FACADE_H
#include <SceneManager.h>
#include <Conroller.h>
#include <BigModelManager.h>
#include <my_exception.h>
#include <QGraphicsScene>

class Facade
{

    Controller *controller;
    BigModelManager *bigmodelmanager;
    SceneManager  *scenemanager;
    Ui::MainWindow *ui;

public:
    Facade();
    ~Facade();
    void scaled();
    void rotated();
    void shifted();
    void camera_changed();
    void open_file(string sourceName);
    void getui(Ui::MainWindow *&ui1);
    void setCamera();
    QGraphicsScene* get_scene();


};

#endif // FACADE_H
