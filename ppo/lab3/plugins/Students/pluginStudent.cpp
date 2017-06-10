#include "pluginStudent.h"
#include "Comands.h"
#include "SComand.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
//#include <TreeModel.h>


QVariant StudentsPlugin::doThing(MainWindow* _th)
{
    QPushButton* openFileButton = new QPushButton("Open Students File");

    connect(openFileButton, SIGNAL(clicked()), this, SLOT(onOpenFileClicked()));
    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(openFileButton);
    PluginsWidget = th->ui->pluginsWidget;
    undoStack = th->undoStack;
    treeView = th->ui->treeView;
    std::cout << "BUtton open file shoud be added" << std::endl;
}
void StudentsPlugin::onOpenFileClicked()
{
    std::cout << "OpenFile Clicked" << std::endl;
    std::cout<<"temp2"<<std::endl;
    std::cout<<th<<std::endl;
    std::cout<<th->ui<<std::endl;
    std::cout<<PluginsWidget<<std::endl;

    //std::cout<<th->ui->pluginsWidget<<std::endl;

    std::cout<<(PluginsWidget==nullptr?"dd":"nodd")<<std::endl;
    std::cout<<"temp3"<<std::endl;

    QString fileName = QFileDialog::getOpenFileName(PluginsWidget,
        tr("Open Student's File"), "./", tr("Json(*.json)"));
    std::cout << "file selected" << std::endl;
    std::cout << fileName.toStdString() << std::endl;
    LoadStudentsCommand* loadCommand = new LoadStudentsCommand(fileName,treeView);
    std::cout << "befor push" << std::endl;
    undoStack->push(loadCommand);
}
