/********************************************************************************
** Form generated from reading UI file 'changestudent.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESTUDENT_H
#define UI_CHANGESTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeStudent
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *m_surname;
    QLineEdit *m_name;
    QLineEdit *m_secondName;
    QLineEdit *m_raiting;
    QLineEdit *m_role;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_cancel;
    QPushButton *m_ok;

    void setupUi(QDialog *ChangeStudent)
    {
        if (ChangeStudent->objectName().isEmpty())
            ChangeStudent->setObjectName(QStringLiteral("ChangeStudent"));
        ChangeStudent->resize(413, 249);
        QFont font;
        font.setPointSize(16);
        ChangeStudent->setFont(font);
        widget = new QWidget(ChangeStudent);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 395, 230));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_surname = new QLineEdit(widget);
        m_surname->setObjectName(QStringLiteral("m_surname"));

        verticalLayout_2->addWidget(m_surname);

        m_name = new QLineEdit(widget);
        m_name->setObjectName(QStringLiteral("m_name"));

        verticalLayout_2->addWidget(m_name);

        m_secondName = new QLineEdit(widget);
        m_secondName->setObjectName(QStringLiteral("m_secondName"));

        verticalLayout_2->addWidget(m_secondName);

        m_raiting = new QLineEdit(widget);
        m_raiting->setObjectName(QStringLiteral("m_raiting"));

        verticalLayout_2->addWidget(m_raiting);

        m_role = new QLineEdit(widget);
        m_role->setObjectName(QStringLiteral("m_role"));

        verticalLayout_2->addWidget(m_role);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_cancel = new QPushButton(widget);
        m_cancel->setObjectName(QStringLiteral("m_cancel"));

        horizontalLayout_2->addWidget(m_cancel);

        m_ok = new QPushButton(widget);
        m_ok->setObjectName(QStringLiteral("m_ok"));

        horizontalLayout_2->addWidget(m_ok);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(ChangeStudent);

        QMetaObject::connectSlotsByName(ChangeStudent);
    } // setupUi

    void retranslateUi(QDialog *ChangeStudent)
    {
        ChangeStudent->setWindowTitle(QApplication::translate("ChangeStudent", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeStudent", "Input Surname:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangeStudent", "Input Name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangeStudent", "Input Second name:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChangeStudent", "Input Raiting:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ChangeStudent", "Input Role:", Q_NULLPTR));
        m_cancel->setText(QApplication::translate("ChangeStudent", "Cancel", Q_NULLPTR));
        m_ok->setText(QApplication::translate("ChangeStudent", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeStudent: public Ui_ChangeStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESTUDENT_H
