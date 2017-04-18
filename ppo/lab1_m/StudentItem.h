#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>
#include <QVector>
class GroupItem;

class StudentItem
{
public:
    StudentItem(int _position);
    struct Student{
        QString name;
        QString surname;
        QString secondName;
        int rating;
        QString role;
    };

public:
    explicit StudentItem();

    void setData(Student &value);
    int getPosition() const;


private:

    Student student;
    GroupItem *parentItem;
    int position;

};

#endif // TREEITEM_H
