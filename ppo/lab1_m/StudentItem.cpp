#include "StudentItem.h"


StudentItem::StudentItem(int _position)
{
    position = _position;
}

void StudentItem::setData(Student &value)
{
    student = value;
}

int StudentItem::getPosition() const
{
    return  position;
}
