#include <SceneObjectManager.h>
#include <typeinfo>
SetModelManager::SetModelManager(Scene *&temp)
{
    scene = temp;
}

void SetModelManager::setModelsParams(new_params temp)
{
    auto size = scene->obj.size();
    auto& array = scene->obj;
    for (int i = 0; i < size; i++) {

        try {
            if (array[i]->enable) {
                auto my_b = dynamic_cast<PrototypeModel*>(array[i]);

                if (my_b->whatIsIt() == "ConcreteModel1") {

                    auto my_b1 = dynamic_cast<ConcreteModel1*>(array[i]);
                    my_b1->dx += temp.dx;
                    my_b1->dy += temp.dy;
                    my_b1->dz += temp.dy;
                    my_b1->fx += temp.fx;
                    my_b1->fy += temp.fy;
                    my_b1->fz += temp.fz;
                    my_b1->M *= temp.M;
                    break;
                }
            }

        } catch (const std::bad_cast& e) {
            continue;
        }
    }
    //если все в порядке
}
