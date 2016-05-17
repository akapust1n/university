#ifndef SHOWSCENEOBJECTSMANAGER_H
#define SHOWSCENEOBJECTSMANAGER_H
#include <QPoint>
#include <QGraphicsScene>
#include <SceneObjects.h>
#include <structures.h>
class ShowSceneObjectManager{
public:
    virtual void getScene(int scene) = 0;

};
class DrawCarcasManager:public ShowSceneObjectManager {
public:
    virtual void drawModel(PrototypeModel *model) = 0;
    void DrawLine(QPoint p1,QPoint p2,QGraphicsScene *scene);

};
class DrawConcreteModel1:public DrawCarcasManager
{
public:
    virtual void getScene(QGraphicsScene *&temp);
    virtual void drawModel(ConcreteModel1 &model,sConvertedPoints &points);
    void getDrawableEdge(QPoint &p1, QPoint &p2, sConvertedPoints &points, int *links, int i);
private:
    QGraphicsScene *scene;
};

#endif // SHOWSCENEOBJECTSMANAGER_H
