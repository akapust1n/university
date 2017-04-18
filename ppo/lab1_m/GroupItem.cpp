#include "GroupItem.h"

#include <QStringList>

GroupItem::GroupItem(int _number)
{
    number = _number;
}

GroupItem::~GroupItem()
{
    qDeleteAll(childs);
}

StudentItem* GroupItem::child(int number)
{
    return childs.value(number);
}

QVariant GroupItem::data() const
{
    return QVariant(itemData);
}

int GroupItem::getNumChilds() const
{
   return childs.size();
}

void GroupItem::insertChildren(StudentItem* child)
{
    childs.append(child);
}

void GroupItem::removeChildren(int position)
{
    for (auto& temp : childs) {
        if (temp->getPosition() == position) {
            delete temp;
            break;
        }
    }
}

void GroupItem::setData( const QString &value)
{
    itemData= value;
}

QString GroupItem::getGroup() const
{
    return  itemData;
}


