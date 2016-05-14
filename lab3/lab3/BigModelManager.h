#ifndef BIGDATAMANAGER_H
#define BIGDATAMANAGER_H
#include <string>
#include <Scene.h>
using namespace  std;
class BigModelManager{
public:
    BigModelManager();
    void callDataManager(string sourceName);
    Scene scene;

};

#endif // BIGDATAMANAGER_H
