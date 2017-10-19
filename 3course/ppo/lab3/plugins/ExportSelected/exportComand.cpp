#include "exportComand.h"
#include <QFile>
#include <QTextStream>

exportComand::exportComand(QModelIndex _selected, QString _filename, TreeModel *_treeModel)
    : selected(_selected),
     filename(_filename),
     treeModel(_treeModel)
{
}


void exportComand::undo()
{
    QFile file(filename);
    file.remove();
}

void exportComand::redo()
{

    QFile result(filename);
    if (result.open(QIODevice::ReadWrite)) {
        std::cout<<"redo export phase2"<<std::endl;
        std::cout<<selected.data().toString().toStdString()<<std::endl;

        QTextStream stream(&result);
       // for(int i = 1; i<treeModel->columnCount2(selected);i++) {
            std::cout<<"SELECTED1"<<selected.data().toString().toStdString()<<std::endl;
            stream<<selected.data().toString()<<endl;
        //}
    }

    std::cout<<"redo export phase3"<<std::endl;

    result.close();
    std::cout<<"redo export phase4"<<std::endl;

}
