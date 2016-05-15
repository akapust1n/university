#include <BigModelManager.h>
#include <DataManager.h>
#include <iostream>
#include <Scene.h>
#include <my_exception.h>
#include <typeinfo>
BigModelManager::BigModelManager()
{
}
void BigModelManager::callDataManager(string sourceName)
{
    ConcreteDataManager data(sourceName);
    PrototypeModel *temp = nullptr;

     temp = data.getModel();

    scene.addElement(temp);



}
