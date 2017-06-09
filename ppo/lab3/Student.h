#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    enum Role {
        student,
        head
    };

    Student(){}
    Student(QString &surname, QString &name, QString &secondName,
            int raiting, QString &group, Role role);
    Student(const Student &obj);

    void setSurname(QString &surname);
    QString getSurname();

    void setName(QString &name);
    QString getName();

    void setSecondname(QString &secondName);
    QString getSecondName();

    void setRaiting(int raiting);
    int getRaiting();

    void setGroup(QString &group);
    QString getGroup();

    void setRole(Role role);
    Role getRole();

private:
    QString m_surname;
    QString m_name;
    QString m_secondName;
    int m_raiting;
    QString m_group;
    Role m_role;
};

#endif // STUDENT_H
