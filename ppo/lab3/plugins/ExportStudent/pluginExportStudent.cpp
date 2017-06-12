#include "pluginExportStudent.h"
#include "Comands.h"
#include <QFileDialog>
#include <QPushButton>
#include <iostream>
//#include <TreeModel.h>
#include <QVariant>
#include <QVector>
#include <SaveFileAs.h>

QVariant StudentsExportPlugin::doThing(MainWindow* _th)
{
    QPushButton* exportStudent = new QPushButton("Export student");
    connect(exportStudent, SIGNAL(clicked()), this, SLOT(onExportStudentClicked()));

    th = _th;
    th->ui->pluginsWidget->layout()->addWidget(exportStudent);
    PluginsWidget = th->ui->pluginsWidget;
    undoStack = th->undoStack;
    treeView = th->ui->treeView;
    treeModel = th->treeModel;
    std::cout << "BUtton export shoud be added" << std::endl;
}
void StudentsExportPlugin::onExportStudentClicked()
{
    if (treeView->selectionModel()) {
        list = treeView->selectionModel()->selectedIndexes();
        QModelIndex tnh = list.first();
        std::cout << "export student clicked phase1" << std::endl;
        std::cout << tnh.parent().data().toString().toStdString() << std::endl;
        if (list.size() > 0) {
            if (tnh.parent().data().toString() == "Groups") {
                std::cout << "export student clicked phase2" << std::endl;

                SaveFileAs* saveFileAs = new SaveFileAs(tnh, treeModel, undoStack, PluginsWidget);
                saveFileAs->show();
            }
        }
    }
    std::cout << "export student clicked phase3" << std::endl;
}
