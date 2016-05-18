#include <ShowSceneObjectsManager.h>
#include <iostream>
void DrawCarcasManager::DrawLine(QPoint p1, QPoint p2, QGraphicsScene*&scene1)
{
    if(!scene1)
        std::cout<<"lol";
   // QGraphicsScene sc1;
     //sc1.addLine(0,0,20,30);

    scene1->addLine(p1.x(), p1.y(), p2.x(), p2.y(),QPen(QColor(0, 0, 0), 3, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
    return;
}
void DrawConcreteModel1::drawModel(ConcreteModel1& model, sConvertedPoints*& points)
{
    for (int i = 0; i < model.edge_num; i += 2) {
        QPoint p1;
        QPoint p2;
        getDrawableEdge(p1, p2, points, model.links, i);
        DrawLine(p1, p2, scene);
    }
}
void DrawConcreteModel1::getDrawableEdge(QPoint& p1, QPoint& p2, sConvertedPoints*& points, int* links, int i)
{

    p1.setX(points->Xs[links[i]]);
    p2.setX(points->Ys[links[i]]);
    p2.setX(points->Xs[links[i+1]]);
    p2.setX(points->Ys[links[i+1]]);
}
void DrawConcreteModel1::getScene(QGraphicsScene *&temp)
{
    scene = temp;

}
 void DrawCarcasManager:: drawModel(PrototypeModel *model){}
