#include <BigModelManager.h>
#include <DataManager.h>
#include <iostream>
 BigModelManager::BigModelManager()
{

}
void BigModelManager::callDataManager(string sourceName)
{
     ConcreteDataManager data(sourceName);
     data.getModel();

     //std::cout<<"lol";

}
