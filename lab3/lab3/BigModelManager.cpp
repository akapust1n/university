#include <BigModelManager.h>
#include <DataManager.h>
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
void BigModelManager::callDataManager(string sourceName)
{
    ConcreteDataManager data(sourceName);
    PrototypeModel* temp = nullptr;
    temp = data.getModel();
    scene->addElement(temp);
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
