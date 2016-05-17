#ifndef BIGDATAMANAGER_H
#define BIGDATAMANAGER_H
using namespace  std;
#include <string>
#include <Scene.h>
#include <structures.h>
#include <SceneObjectManager.h>
#include <Conroller.h>
class BigModelManager{
private:
    Controller *controller;
public:
    BigModelManager();
    void callDataManager(string sourceName);
    void callSetSceneObjectManager(pick action);
    Scene scene;
    void setContoller(Controller &temp);



};

#endif // BIGDATAMANAGER_H
