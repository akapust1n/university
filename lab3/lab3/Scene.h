#ifndef SCENE_H
#define SCENE_H
#include <SceneObjects.h>
#include <vector>
//синглтон
class Scene {
public:
    void addElement(SceneObject *param);

private:
    std::vector <SceneObject*> obj;
};
#endif // SCENE_H
