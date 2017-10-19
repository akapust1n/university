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
    std::cout<<"COLUMN COUNT"<<treeModel->getRootItem()<<std::endl;
    //std::cout<<"dd "<<treeModel->columnCount(temp)<<std::endl;
    QStringList students;
    for (int i = 0; i < treeModel->rowCount2(group); i++) {
        std::cout<<"append export "<<i<<std::endl;
        QString namePlusSurname = group.child(i,0 ).data(0).toString()+QString(" ") + group.child(i,1).data(0).toString();
        students.append(namePlusSurname);
        std::cout<<"STUDENT1"<<group.child(i,0 ).data(0).toString().toStdString()<<std::endl;
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
