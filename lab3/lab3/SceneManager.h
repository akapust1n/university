
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <vector>
#include <ui_mainwindow.h>
#include <Scene.h>
namespace Ui {
class MainWindow;
}
class SceneManager {
public:
    void setupUi(Ui::MainWindow*& temp, Scene *&temp2);
    void drawModels();

private slots:
    void on_doButton_clicked();

private:
    Ui::MainWindow *ui;
    Scene *Qscene;

};

#endif // SCENEMANAGER_H
