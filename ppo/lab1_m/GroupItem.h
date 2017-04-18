#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QList>
#include <QVariant>
#include <QVector>
#include <StudentItem.h>

class GroupItem {

public:
    GroupItem(int _number);
    ~GroupItem();

    StudentItem *child(int number);
    QVariant data() const;
    int getNumChilds() const;

    void insertChildren(StudentItem *child);
    void removeChildren(int position);

    void setData(const QString& value);
    void setChildData(int position,const StudentItem* child);
    QString getGroup() const;

private:
    QList<StudentItem*> childs;
    QString itemData;
    int number;
};
#endif // GROUPITEM_H
