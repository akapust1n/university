#include "exportComand.h"
#include <QFile>
#include <QTextStream>

exportComand::exportComand(QModelIndex _selected, QString _filename)
    : selected(_selected),
     filename(_filename)
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

        QTextStream stream(&result);
        stream<<selected.data().toString()<<endl;
    }

    std::cout<<"redo export phase3"<<std::endl;

    result.close();
    std::cout<<"redo export phase4"<<std::endl;

}
