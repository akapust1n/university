#include "ExportStudentComand.h"
#include <QFile>
#include <QTextStream>

ExportStudentComand::ExportStudentComand(QModelIndex _group, QString _filename, TreeModel* _treeModel)
    : group(_group),
     treeModel(_treeModel)
    , filename(_filename)
{
}


void ExportStudentComand::undo()
{
    QFile file(filename);
    file.remove();
}

void ExportStudentComand::redo()
{
    std::cout<<"redo export phase1"<<std::endl;
    std::cout<<treeModel<<std::endl;
    std::cout<<group.data().toString().toStdString()<<std::endl;
    std::cout<<"COLUMN COUNT"<<treeModel->rowCount(group)<<std::endl;
    QStringList students;
    for (int i = 0; i < treeModel->rowCount(group) - 1; i++) {
        std::cout<<"append export "<<i<<std::endl;
        students.append(group.child(treeModel->rowCount(group) - 1, i).data(i).toString()); //Фамилия
    }
    std::cout<<"redo export phase2"<<std::endl;

    QFile result(filename);
    if (result.open(QIODevice::ReadWrite)) {
        QTextStream stream(&result);
        for (int i = 0; i < students.size(); i++)
            stream << students[i] << endl;
    }
    std::cout<<"redo export phase3"<<std::endl;

    result.close();
    std::cout<<"redo export phase4"<<std::endl;

}
