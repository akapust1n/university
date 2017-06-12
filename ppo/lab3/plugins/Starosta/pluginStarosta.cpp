#include "pluginStarosta.h"
#include "Comands.h"
#include "SComand.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
//#include <TreeModel.h>

#include <QVariant>
#include <QVector>

QVariant StarostaPlugin::doThing(MainWindow* _th)
{
    QPushButton* openFileButton = new QPushButton("Statosta Comand");
    connect(openFileButton, SIGNAL(clicked()), this, SLOT(onOpenFileClicked()));
    QPalette pal = openFileButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::green));
    openFileButton->setAutoFillBackground(true);
    openFileButton->setPalette(pal);
    openFileButton->update();
    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(openFileButton);
    PluginsWidget = th->ui->pluginsWidget;
    undoStack = th->undoStack;
    treeView = th->tree->treeView;
    tree = th->tree;
    std::cout << "BUtton open file shoud be added" << std::endl;
}
void StarostaPlugin::onOpenFileClicked()
{
    list = treeView->selectionModel()->selectedIndexes();
    QModelIndex tnh = list.first().parent();
    if (tnh.parent().data().toString() == "Groups") {
        QModelIndex tnh2 = list.first();

        QModelIndex tnh3 = list.at(4);
        std::cout << "DATA " << tnh2.data(4).toString().toStdString() << std::endl;
        std::cout << "DATA " << tnh.data().toString().toStdString() << std::endl;
        std::cout << "DATA " << tnh3.data().toString().toStdString() << std::endl;

        if (tnh3.data().toString() == "head") {
            SCommand* sCommand = new SCommand(tnh2);
            std::cout << "befor push" << std::endl;
            undoStack->push(sCommand);
        }
    }
}
