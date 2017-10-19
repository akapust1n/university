#ifndef SCENE_H
#define SCENE_H
#include <SceneObjects.h>
#include <vector>
#include <QGraphicsScene>
//синглтон
class Scene {
public:
    Scene();
    ~Scene();

    QGraphicsScene *scene;
    Scene(const Scene &obj);

    void addElement(Composite *param);
    std::vector <Composite*> obj;
};
#endif // SCENE_H
