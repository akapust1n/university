#include <Converter.h>
#include <SceneManager.h>
#include <ShowSceneObjectsManager.h>
#include <typeinfo>
#include <iostream>
#include <QMessageBox>
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
    std::cout<<size; //тест
    auto& array = Qscene->obj;
    clear();
    for (int i = 0; i < size; i++) {
        try {
            if (array[i]->enable) {
                auto my_b = dynamic_cast<PrototypeModel*>(array[i]);

                if (my_b->whatIsIt() == "ConcreteModel1") {

                    auto my_b1 = dynamic_cast<ConcreteModel1*>(array[i]);
                    ConcreteConverter1 temp;
                    DrawConcreteModel1 mt;

                    mt.getScene(Qscene->scene);
                    //не очень удачно каждый раз объект создавать, да и всё то, что выше - не круто
                    sConvertedPoints* points1 = temp.getConvertedPoints(my_b1);

                    mt.drawModel(*my_b1, points1);

                }
            }

        } catch (const std::bad_cast& e) {
            continue;
        }
    }
}

void SceneManager::on_doButton_clicked()
{
}
