#include "Student.h"

Student::Student(QString& surname, QString& name, QString& secondName,
    int raiting, QString& group, Role role)
    : m_surname(surname)
    , m_name(name)
    , m_secondName(secondName)
    , m_raiting(raiting)
    , m_group(group)
    , m_role(role)
{
}

Student::Student(const Student& obj)
    : m_surname(obj.m_surname)
    , m_name(obj.m_name)
    , m_secondName(obj.m_secondName)
    , m_raiting(obj.m_raiting)
    , m_group(obj.m_group)
    , m_role(obj.m_role)
{
}

void Student::setSurname(QString& surname)
{
    this->m_surname = surname;
}

QString Student::getSurname()
{
    return this->m_surname;
}

void Student::setName(QString& name)
{
    this->m_name = name;
}

QString Student::getName()
{
    return this->m_name;
}

void Student::setSecondname(QString& secondName)
{
    this->m_secondName = secondName;
}

QString Student::getSecondName()
{
    return this->m_secondName;
}

void Student::setRaiting(int raiting)
{
    this->m_raiting = raiting;
}

int Student::getRaiting()
{
    return this->m_raiting;
}

void Student::setGroup(QString& group)
{
    this->m_group = group;
}

QString Student::getGroup()
{
    return this->m_group;
}

void Student::setRole(Student::Role role)
{
    this->m_role = role;
}

Student::Role Student::getRole()
{
    return this->m_role;
}
