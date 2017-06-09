#ifndef INFOBYTREE_H
#define INFOBYTREE_H

#include <QTreeWidget>
#include <QString>
#include "Student.h"

typedef QVector<Student> Students;

class InfoByTree
{
public:
    InfoByTree();

    void showInfo(QTreeWidget *viewer, Students group);

private:
    QTreeWidgetItem *addRoot(QTreeWidget *viewer, QString name);
    QTreeWidgetItem *addGroup(QTreeWidgetItem *parent, QString name);
    void addStudentInfo(QTreeWidgetItem *group, Student tmp);
};

#endif // INFOBYTREE_H
