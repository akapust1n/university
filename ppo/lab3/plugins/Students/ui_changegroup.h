/********************************************************************************
** Form generated from reading UI file 'changegroup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEGROUP_H
#define UI_CHANGEGROUP_H

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

class Ui_ChangeGroup
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_groupName;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_cancel;
    QPushButton *m_ok;

    void setupUi(QDialog *ChangeGroup)
    {
        if (ChangeGroup->objectName().isEmpty())
            ChangeGroup->setObjectName(QStringLiteral("ChangeGroup"));
        ChangeGroup->resize(396, 96);
        QFont font;
        font.setPointSize(16);
        ChangeGroup->setFont(font);
        widget = new QWidget(ChangeGroup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 11, 381, 78));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        m_groupName = new QLineEdit(widget);
        m_groupName->setObjectName(QStringLiteral("m_groupName"));

        horizontalLayout->addWidget(m_groupName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_cancel = new QPushButton(widget);
        m_cancel->setObjectName(QStringLiteral("m_cancel"));

        horizontalLayout_2->addWidget(m_cancel);

        m_ok = new QPushButton(widget);
        m_ok->setObjectName(QStringLiteral("m_ok"));

        horizontalLayout_2->addWidget(m_ok);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(ChangeGroup);

        QMetaObject::connectSlotsByName(ChangeGroup);
    } // setupUi

    void retranslateUi(QDialog *ChangeGroup)
    {
        ChangeGroup->setWindowTitle(QApplication::translate("ChangeGroup", "Change Group Info", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeGroup", "Input Group name:", Q_NULLPTR));
        m_cancel->setText(QApplication::translate("ChangeGroup", "Cancel", Q_NULLPTR));
        m_ok->setText(QApplication::translate("ChangeGroup", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeGroup: public Ui_ChangeGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEGROUP_H
