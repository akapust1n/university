#ifndef SCENEOBJECTS_H
#define SCENEOBJECTS_H
class SceneObject {
protected:
    bool enable;
};
class VisibleObject : public SceneObject {
};
class InvisibleObjects : public SceneObject {
};

class PrototypeModel : public VisibleObject {
protected:
    int vertices;
    int *links;
    double fx, fy, fz; //угол поворота
    double dx, dy, dz; //смещение модели
    double M; //масштаб отрисовки
};

class ConcreteModel1 : public PrototypeModel {
private:
    int edge_num;
    double* x;
    double* y;
    double* z;

};

#endif // SCENEOBJECTS_H
