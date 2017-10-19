#include "pluginStudent.h"
#include "Comands.h"
#include "LoadComand.h"
#include "RemoveComand.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
//#include <TreeModel.h>
#include "ChangeGroup.h"
#include "ChangeStudent.h"
#include "InsertGroup.h"
#include "InsertStudent.h"
#include <QVariant>
#include <QVector>
#include "QMessageBox"

QVariant StudentsPlugin::doThing(MainWindow* _th)
{
    QPushButton* openFileButton = new QPushButton("Open Students File");
    connect(openFileButton, SIGNAL(clicked()), this, SLOT(onOpenFileClicked()));

    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(openFileButton);
    PluginsWidget = th->ui->pluginsWidget;
    undoStack = th->undoStack;
    treeView = th->tree->treeView;
    tree =  th->tree;
    std::cout << "BUtton open file shoud be added" << std::endl;

    QPushButton* removeStudentsButton = new QPushButton("Remove students/gr");
    th->ui->pluginsWidget->layout()->addWidget(removeStudentsButton);
    connect(removeStudentsButton, SIGNAL(clicked()), this, SLOT(onRemoveStudentsClicked()));

    QPushButton* insertButton = new QPushButton("Insert st/group");
    th->ui->pluginsWidget->layout()->addWidget(insertButton);
    connect(insertButton, SIGNAL(clicked()), this, SLOT(onInsertClicked()));

    QPushButton* changeButton = new QPushButton("Change st/group");
    th->ui->pluginsWidget->layout()->addWidget(changeButton);
    connect(changeButton, SIGNAL(clicked()), this, SLOT(onChangeClicked()));

}
void StudentsPlugin::onOpenFileClicked()
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
    LoadStudentsCommand* loadCommand = new LoadStudentsCommand(fileName, treeView);
    std::cout << "befor push" << std::endl;
    undoStack->push(loadCommand);
    tree->treeModel = loadCommand->getTreeModel(); // :)))
    treeModel = tree->treeModel;
    tree->kindTree = new QString("STUDENTS");
}

void StudentsPlugin::onRemoveStudentsClicked()
{
    if(tree->kindTree ==QString("STUDENTS")) {

    list = treeView->selectionModel()->selectedIndexes();
    std::cout << "Start remove students" << std::endl;
    QModelIndex tnh = list.first();
    if (tnh.data().toString() != "Groups") {
        QVector<QVariant> data;
        QVector<QVector<QVariant> > allData;
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

        RemoveCommand* removeComand = new RemoveCommand(tnh, allData, treeModel);
        undoStack->push(removeComand);
    }
    }
    else{
        QMessageBox box;
        box.setText("It is not student!");
        box.exec();
    }
}

void StudentsPlugin::onInsertClicked()
{
    if(tree->kindTree ==QString("STUDENTS")) {

    list = treeView->selectionModel()->selectedIndexes();
    QModelIndex tnh = list.first();
    if (tnh.data().toString() == "Groups") {
        InsertGroup* insrtGrp = new InsertGroup(tnh, treeModel, undoStack, PluginsWidget);
        insrtGrp->show();
    } else if (tnh.parent().data().toString() == "Groups") {
        InsertStudent* stdntChng = new InsertStudent(tnh, treeModel, undoStack, PluginsWidget);
        stdntChng->show();
    }
    }
    else{
        QMessageBox box;
        box.setText("It is not student!");
        box.exec();
    }
}

void StudentsPlugin::onChangeClicked()
{
    if(tree->kindTree ==QString("STUDENTS")) {

    list = treeView->selectionModel()->selectedIndexes();
    QModelIndex tnh = list.first().parent();
    if (tnh.data().toString() == "Groups") {
        ChangeGroup* grpChng = new ChangeGroup(treeView, list.first().data().toString(), treeModel, undoStack, PluginsWidget);
        grpChng->show();
    } else if (tnh.parent().data().toString() == "Groups") {

        ChangeStudent *stdntChng = new ChangeStudent(treeView,treeModel,undoStack,PluginsWidget);
        stdntChng->show();
    }
    }
    else{
        QMessageBox box;
        box.setText("It is not student!");
        box.exec();
    }
}
