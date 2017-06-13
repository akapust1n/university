#include "pluginTeacher.h"
#include "Comands.h"
#include "LoadComand.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
//#include <TreeModel.h>

#include <QVariant>
#include <QVector>

QVariant TeachersPlugin::doThing(MainWindow* _th)
{
    QPushButton* openFileButton = new QPushButton("Open Teachers File");
    connect(openFileButton, SIGNAL(clicked()), this, SLOT(onOpenFileClicked()));
    QPalette pal = openFileButton ->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    openFileButton ->setAutoFillBackground(true);
    openFileButton ->setPalette(pal);
    openFileButton->update();
    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(openFileButton);
    PluginsWidget = th->ui->pluginsWidget;
    undoStack = th->undoStack;
    treeView = th->tree->treeView;
    tree =  th->tree;
    std::cout << "BUtton open file shoud be added" << std::endl;
}
void TeachersPlugin::onOpenFileClicked()
{
    std::cout << "OpenFile Clicked" << std::endl;
    std::cout << "temp2" << std::endl;
    std::cout << th << std::endl;
    std::cout << th->ui << std::endl;
    std::cout << PluginsWidget << std::endl;

    //std::cout<<th->ui->pluginsWidget<<std::endl;

    std::cout << (PluginsWidget == nullptr ? "dd" : "nodd") << std::endl;
    std::cout << "temp3" << std::endl;

    QString fileName = QFileDialog::getOpenFileName(PluginsWidget,
        tr("Open Student's File"), "./", tr("Json(*.json)"));
    std::cout << "file selected" << std::endl;
    std::cout << fileName.toStdString() << std::endl;
    LoadTeachersCommand* loadCommand = new LoadTeachersCommand(fileName, treeView);
    std::cout << "befor push" << std::endl;
    undoStack->push(loadCommand);
    tree->treeModel = loadCommand->getTreeModel(); // :)))
    treeModel = tree->treeModel;
    tree->kindTree = new QString("TEACHERS");

}

