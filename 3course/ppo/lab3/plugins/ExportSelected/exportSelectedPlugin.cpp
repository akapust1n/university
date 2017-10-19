#include "exportSelectedPlugin.h"
#include "Comands.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
//#include <TreeModel.h>
#include <QVariant>
#include <QVector>
#include <SaveFileAs.h>

QVariant  exportSelectedPlugin ::doThing(MainWindow* _th)
{
    QPushButton* exportStudent = new QPushButton("Export selected");
    connect(exportStudent, SIGNAL(clicked()), this, SLOT(onExportClicked()));

    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(exportStudent);
    PluginsWidget = th->ui->pluginsWidget;
    undoStack = th->undoStack;
    treeView = th->tree->treeView;
    treeModel = th->tree->treeModel;
    std::cout << "BUtton export shoud be added" << std::endl;
}
void  exportSelectedPlugin ::onExportClicked()
{
    if (treeView->selectionModel()) {
        list = treeView->selectionModel()->selectedIndexes();
        QModelIndex tnh = list.first();
        std::cout << "export student clicked phase1" << std::endl;
        std::cout << tnh.parent().data().toString().toStdString() << std::endl;
        if (list.size() > 0) {
                std::cout << "export student clicked phase2" << std::endl;

                SaveFileAs* saveFileAs = new SaveFileAs(tnh, treeModel, undoStack, PluginsWidget);
                saveFileAs->show();
            }

    }
}
