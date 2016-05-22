#include <SceneObjectManager.h>
#include <typeinfo>
SetModelManager::SetModelManager(Scene*& temp)
{
    scene = temp;
}

void SetModelManager::setModelsParams(new_params temp)
{

    for (int z = 0; z < scene->obj.size(); z++) {
        Composite* temp1 = scene->obj[z];
        auto size = temp1->vect.size();
        auto& array = temp1->vect;
        for (int i = 0; i < size; i++) {

            try {
                if (array[i]->enable) {
                    auto my_b = dynamic_cast<PrototypeModel*>(array[i]);
                    if (my_b != nullptr) {
                        if (my_b->whatIsIt() == "ConcreteModel1") {

                            auto my_b1 = dynamic_cast<ConcreteModel1*>(array[i]);
                            my_b1->dx += temp.dx;
                            my_b1->dy += temp.dy;
                            my_b1->dz += temp.dy;
                            my_b1->fx += temp.fx;
                            my_b1->fy += temp.fy;
                            my_b1->fz += temp.fz;
                            my_b1->M *= temp.M;
                        }
                    }
                }

            } catch (const std::bad_cast& e) {
                continue;
            }
        }
    }
    //если все в порядке
}
SetCameraManager::SetCameraManager(Scene*& temp)
{
    scene = temp;
}
void SetCameraManager::setCameraParams(new_params temp)
{

    for (int z = 0; z < scene->obj.size(); z++) {
        Composite* temp1 = scene->obj[z];
        auto size = temp1->vect.size();
        auto& array = temp1->vect;
        for (int i = 0; i < size; i++) {

            try {
                if (array[i]->enable) {
                    auto my_b = dynamic_cast<PrototypeCamera*>(array[i]);
                    if (my_b != nullptr) {
                        if (my_b->whatIsIt() == "ConcreteCamera1") {

                            auto my_b1 = dynamic_cast<ConcreteCamera1*>(array[i]);
                            my_b1->x = temp.dx;
                            my_b1->y = temp.dy;
                            my_b1->z = temp.dy;
                        }
                    }
                }

            } catch (const std::bad_cast& e) {
                continue;
            }
        }
    }
    //если все в порядке
}
