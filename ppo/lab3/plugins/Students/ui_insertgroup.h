/********************************************************************************
** Form generated from reading UI file 'insertgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTGROUP_H
#define UI_INSERTGROUP_H

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

class Ui_InsertGroup
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_groupName;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_cancel;
    QPushButton *m_ok;

    void setupUi(QDialog *InsertGroup)
    {
        if (InsertGroup->objectName().isEmpty())
            InsertGroup->setObjectName(QStringLiteral("InsertGroup"));
        InsertGroup->resize(397, 97);
        QFont font;
        font.setPointSize(16);
        InsertGroup->setFont(font);
        layoutWidget = new QWidget(InsertGroup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 78));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        m_groupName = new QLineEdit(layoutWidget);
        m_groupName->setObjectName(QStringLiteral("m_groupName"));

        horizontalLayout->addWidget(m_groupName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_cancel = new QPushButton(layoutWidget);
        m_cancel->setObjectName(QStringLiteral("m_cancel"));

        horizontalLayout_2->addWidget(m_cancel);

        m_ok = new QPushButton(layoutWidget);
        m_ok->setObjectName(QStringLiteral("m_ok"));

        horizontalLayout_2->addWidget(m_ok);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(InsertGroup);

        QMetaObject::connectSlotsByName(InsertGroup);
    } // setupUi

    void retranslateUi(QDialog *InsertGroup)
    {
        InsertGroup->setWindowTitle(QApplication::translate("InsertGroup", "Add Group", Q_NULLPTR));
        label->setText(QApplication::translate("InsertGroup", "Input Group name:", Q_NULLPTR));
        m_groupName->setText(QApplication::translate("InsertGroup", "Group Name", Q_NULLPTR));
        m_cancel->setText(QApplication::translate("InsertGroup", "Cancel", Q_NULLPTR));
        m_ok->setText(QApplication::translate("InsertGroup", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InsertGroup: public Ui_InsertGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTGROUP_H
