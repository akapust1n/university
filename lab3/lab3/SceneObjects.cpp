#include <SceneObjects.h>
PrototypeModel::PrototypeModel():dx(0),dy(0),dz(0),fx(0),fy(0),fz(0),M(1)
{

}
ConcreteModel1::ConcreteModel1():PrototypeModel()
{
    enable = true;
}
