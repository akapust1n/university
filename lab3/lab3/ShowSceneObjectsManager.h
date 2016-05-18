#ifndef SHOWSCENEOBJECTSMANAGER_H
#define SHOWSCENEOBJECTSMANAGER_H
#include <QPoint>
#include <QGraphicsScene>
#include <SceneObjects.h>
#include <structures.h>
class ShowSceneObjectManager{
public:
    //virtual void getScene(QGraphicsScene *&temp);

};
class DrawCarcasManager:public ShowSceneObjectManager {
public:
    virtual void drawModel(PrototypeModel *model) ; // ДОЛЖНА БЫТЬ АБСТРАКТНОЙ
    void DrawLine(QPoint p1, QPoint p2, QGraphicsScene *&scene);

};
class DrawConcreteModel1:public DrawCarcasManager
{
public:
    virtual void getScene(QGraphicsScene *&temp);
    virtual void drawModel(ConcreteModel1 &model,sConvertedPoints &points);
private:
    void getDrawableEdge(QPoint &p1, QPoint &p2, sConvertedPoints &points, int *links, int i);
    QGraphicsScene *scene;
};

#endif // SHOWSCENEOBJECTSMANAGER_H
