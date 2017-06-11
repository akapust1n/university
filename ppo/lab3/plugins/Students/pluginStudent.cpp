#include "pluginStudent.h"
#include "Comands.h"
#include "LoadComand.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
#include "RemoveComand.h"
//#include <TreeModel.h>
#include <QVector>
#include <QVariant>
#include "InsertGroup.h"


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

    QPushButton* removeStudentsButton= new QPushButton("Remove students");
    th->ui->pluginsWidget->layout()->addWidget(removeStudentsButton);
    connect(removeStudentsButton, SIGNAL(clicked()), this, SLOT(onRemoveStudentsClicked()));

    QPushButton* insertButton= new QPushButton("Insert");
    th->ui->pluginsWidget->layout()->addWidget(insertButton);
    connect(insertButton, SIGNAL(clicked()), this, SLOT(onInsertClicked()));



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
    treeModel = loadCommand->getTreeModel(); // :)))

}

void StudentsPlugin::onRemoveStudentsClicked()
{
    list= treeView->selectionModel()->selectedIndexes();
    std::cout<<"Start remove students"<<std::endl;
    QModelIndex tnh = list.first();
    if (tnh.data().toString() != "Groups") {
        QVector<QVariant> data;
        QVector<QVector<QVariant>> allData;
        foreach (QModelIndex tmp, list) {
            data << tmp.data().toString();
        }
        allData.push_back(data);

        int row = 0;

        while (tnh.child(row, 0).isValid()) {
            QVector<QVariant> subData;
            for (int i = 0; i < 5; i++)
                subData << tnh.child(row, i).data();
            allData.push_back(subData);
            row++;
        }

        RemoveCommand *removeComand = new RemoveCommand(tnh, allData,treeModel);
        undoStack->push(removeComand);
    }
}

void StudentsPlugin::onInsertClicked()
{
    list= treeView->selectionModel()->selectedIndexes();
    QModelIndex tnh = list.first();

    InsertGroup *insrtGrp = new InsertGroup(tnh,treeModel, undoStack,PluginsWidget);
    //insrtGrp->setParam(m_facade, tnh);
    insrtGrp->show();

}
