#include <BigModelManager.h>
#include <DataManager.h>
#include <QMessageBox>
#include <Scene.h>
#include <iostream>
#include <my_exception.h>
#include <typeinfo>
BigModelManager::BigModelManager()
{
    scene = new Scene;
}
BigModelManager::~BigModelManager()
{
    delete scene;
}
//каждый раз добавляем камеру
void BigModelManager::callDataManager(string sourceName)
{
    static int counter = 0;
    ConcreteDataManager data(sourceName);
    PrototypeModel* temp = nullptr;
    temp = data.getModel();

    static Composite* temp2 = new Composite; // создается один композит


    temp2->vect.push_back(temp);

    if (!counter) //костыль для добавления ОДНОГО комозита и одной камеры
    {
        ConcreteCamera1* camera1 = new ConcreteCamera1;
        camera1->x = 1;
        camera1->y = 1;
        camera1->z = 1;
        temp2->vect.push_back(camera1);
        scene->addElement(temp2);
    }
    counter++;
}
void BigModelManager::callSetSceneObjectManager(pick action)
{

    switch (action) {
    case (pick::pick_mash): {
        new_params temp = controller->getParams(pick::pick_mash);
        SetModelManager setmodelmanager(scene);
        setmodelmanager.setModelsParams(temp);
        break;
    }
    case (pick::pick_pov): {
        new_params temp = controller->getParams(pick::pick_pov);
        SetModelManager setmodelmanager(scene);
        setmodelmanager.setModelsParams(temp);
        break;
    }
    case (pick::pick_sdvig): {
        new_params temp = controller->getParams(pick::pick_sdvig);
        SetModelManager setmodelmanager(scene);
        setmodelmanager.setModelsParams(temp);
        break;
    }
    }
}
void BigModelManager::setContoller(Controller*& temp)
{
    controller = temp;
}
