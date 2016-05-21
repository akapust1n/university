#include <Scene.h>
#include <iostream>
#include <typeinfo>

void Scene::addElement(Composite* param)
{
    obj.push_back(param);
}
Scene::Scene()
{
    scene = new QGraphicsScene;
}
Scene::~Scene()
{
    delete scene;
}

Scene::Scene(const Scene& obj)

{
    scene = obj.scene;
}
