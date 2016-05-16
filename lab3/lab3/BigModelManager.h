#ifndef BIGDATAMANAGER_H
#define BIGDATAMANAGER_H
using namespace  std;
#include <string>
#include <Scene.h>
#include <structures.h>
#include <SceneObjectManager.h>

class BigModelManager{
public:
    BigModelManager();
    void callDataManager(string sourceName);
    void callSetSceneObjectManager(pick action);
    Scene scene;



};

#endif // BIGDATAMANAGER_H
