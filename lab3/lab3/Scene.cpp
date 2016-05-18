#include <Scene.h>
#include <typeinfo>
#include <iostream>

void Scene::addElement(SceneObject* param)
{
    obj.push_back(param);


}
Scene::Scene()
{
    scene = new QGraphicsScene;
}
