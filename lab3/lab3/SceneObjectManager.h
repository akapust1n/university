#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <structures.h>
#include <Scene.h>
class SceneObjectManager {
};
class SetModelManager : public SceneObjectManager {
public:
    SetModelManager(Scene *&temp);
    new_params newparam;
    void setModelsParams(new_params temp);
private:
    Scene *scene;
};
class SetCameraManager : public SceneObjectManager {
public:
    SetCameraManager(Scene *&temp);
    new_params newparam;
    void setCameraParams(new_params temp);
private:
    Scene *scene;
};

#endif // SCENEMANAGER_H
