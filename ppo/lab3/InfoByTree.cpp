#include "InfoByTree.h"

InfoByTree::InfoByTree()
{

}

void InfoByTree::showInfo(QTreeWidget *viewer, Students group)
{
    viewer->clear();
    if (group.isEmpty())
        return;

    QTreeWidgetItem *root = addRoot(viewer, QString("Groups"));
    QTreeWidgetItem *groupItem;
    foreach (Student tmp, group) {
        QList<QTreeWidgetItem*> lst = viewer->findItems(tmp.getGroup(), Qt::MatchRecursive, 0);
        if (lst.isEmpty()) {
            groupItem = addGroup(root, tmp.getGroup());
        } else {
            groupItem = lst.first();
        }

        addStudentInfo(groupItem, tmp);
    }
}

QTreeWidgetItem *InfoByTree::addRoot(QTreeWidget *viewer, QString name)
{
    QTreeWidgetItem *root = new QTreeWidgetItem(viewer);
    root->setText(0, name);
    return root;
}

QTreeWidgetItem *InfoByTree::addGroup(QTreeWidgetItem *parent, QString name)
{
    QTreeWidgetItem *child = new QTreeWidgetItem(parent);
    child->setText(0, name);
    return child;
}

void InfoByTree::addStudentInfo(QTreeWidgetItem *group, Student tmp)
{
    QTreeWidgetItem *root = new QTreeWidgetItem(group);
    root->setText(0, tmp.getSurname());
    root->setText(1, tmp.getName());
    root->setText(2, tmp.getSecondName());
    root->setText(3, QString::number(tmp.getRaiting()));
    if (tmp.getRole() == Student::head) {
        root->setText(4, "head");
    } else {
        root->setText(4, "student");
    }
}
