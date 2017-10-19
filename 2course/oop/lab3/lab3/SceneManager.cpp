#include <Converter.h>
#include <QMessageBox>
#include <SceneManager.h>
#include <ShowSceneObjectsManager.h>
#include <iostream>
#include <typeinfo>
void SceneManager::setupUi(Ui::MainWindow*& temp, Scene*& temp2)
{
    ui = temp;
    Qscene = temp2;
}
void SceneManager::clear()
{
    Qscene->scene->clear();
}

void SceneManager::test()
{
    Qscene->scene->addLine(1, 1, 5, 7);
    Qscene->scene->addLine(5, 7, 90, 90);
}

void SceneManager::drawModels()
{
    auto size = Qscene->obj.size();
    std::cout << size; //тест
    auto& array = Qscene->obj;
    auto draw_camera = new ConcreteCamera1;
    clear();
    for (int i = 0; i < size; i++) {
        try {
            Composite* my_temp = Qscene->obj[i];
            auto size1 = my_temp->vect.size();
            //смотрим камеры
            for (int m = 0; m < size1; m++) {
                if (array[m]->enable)
                    try {
                        auto my_b = dynamic_cast<PrototypeCamera*>(my_temp->vect[m]);

                        if (my_b != nullptr) { //я не понимаю почему, но catch не работает тут
                            auto temp100 = my_b->whatIsIt();
                            if (temp100 == "ConcreteCamera1") {
                                draw_camera = dynamic_cast<ConcreteCamera1*>(my_temp->vect[m]);
                            }
                        }
                    }

                    catch (const std::bad_cast& e) {
                    }
            }

            for (int z = 0; z < size1; z++)
                if (array[i]->enable) {
                    auto my_b = dynamic_cast<PrototypeModel*>(my_temp->vect[z]);
                    if (my_b != nullptr) { //я не понимаю почему, но catch не работает тут
                        if (my_b->whatIsIt() == "ConcreteModel1") {

                            auto my_b1 = dynamic_cast<ConcreteModel1*>(my_temp->vect[z]);

                            ConcreteConverter1 temp;
                            DrawConcreteModel1 mt;
                            mt.getScene(Qscene->scene);
                            sConvertedPoints* points1 = temp.getConvertedPoints(my_b1, draw_camera);
                            mt.drawModel(*my_b1, points1);
                        }
                    }
                }
        } catch (const std::bad_cast& e) {
            continue;
        }
    }
    //delete camera;
}

void SceneManager::on_doButton_clicked()
{
}
