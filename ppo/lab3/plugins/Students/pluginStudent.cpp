#include "pluginStudent.h"
#include <QPushButton>
#include "Comands.h"
#include <QFileDialog>
#include <iostream>

QVariant StudentsPlugin::doThing(MainWindow *_th)
{
    QPushButton *openFileButton = new QPushButton("Open Students File");

    connect(openFileButton, SIGNAL(clicked()), this, SLOT(onOpenFileClicked()));
    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(openFileButton);
    std::cout<<"BUtton open file shoud be added"<<std::endl;
}
void StudentsPlugin::onOpenFileClicked()
{
    QString fileName = QFileDialog::getOpenFileName(th->ui->pluginsWidget,
                                                    tr("Open Student's File"), "../source", tr("Json(*.json)"));
    LoadCommand *loadCommand = new LoadCommand(fileName, th->ui->treeView, th->comandManager.get());
    th->undoStack->push(loadCommand);
}