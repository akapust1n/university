/********************************************************************************
** Form generated from reading UI file 'insertsudent.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTSUDENT_H
#define UI_INSERTSUDENT_H

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

class Ui_InsertSudent
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *m_surname_2;
    QLineEdit *m_name_2;
    QLineEdit *m_secondName_2;
    QLineEdit *m_raiting_2;
    QLineEdit *m_role_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_cancel_2;
    QPushButton *m_ok_2;

    void setupUi(QDialog *InsertSudent)
    {
        if (InsertSudent->objectName().isEmpty())
            InsertSudent->setObjectName(QStringLiteral("InsertSudent"));
        InsertSudent->resize(411, 247);
        QFont font;
        font.setPointSize(16);
        InsertSudent->setFont(font);
        layoutWidget = new QWidget(InsertSudent);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 395, 230));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        m_surname_2 = new QLineEdit(layoutWidget);
        m_surname_2->setObjectName(QStringLiteral("m_surname_2"));

        verticalLayout_6->addWidget(m_surname_2);

        m_name_2 = new QLineEdit(layoutWidget);
        m_name_2->setObjectName(QStringLiteral("m_name_2"));

        verticalLayout_6->addWidget(m_name_2);

        m_secondName_2 = new QLineEdit(layoutWidget);
        m_secondName_2->setObjectName(QStringLiteral("m_secondName_2"));

        verticalLayout_6->addWidget(m_secondName_2);

        m_raiting_2 = new QLineEdit(layoutWidget);
        m_raiting_2->setObjectName(QStringLiteral("m_raiting_2"));

        verticalLayout_6->addWidget(m_raiting_2);

        m_role_2 = new QLineEdit(layoutWidget);
        m_role_2->setObjectName(QStringLiteral("m_role_2"));

        verticalLayout_6->addWidget(m_role_2);


        horizontalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        m_cancel_2 = new QPushButton(layoutWidget);
        m_cancel_2->setObjectName(QStringLiteral("m_cancel_2"));

        horizontalLayout_4->addWidget(m_cancel_2);

        m_ok_2 = new QPushButton(layoutWidget);
        m_ok_2->setObjectName(QStringLiteral("m_ok_2"));

        horizontalLayout_4->addWidget(m_ok_2);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(InsertSudent);

        QMetaObject::connectSlotsByName(InsertSudent);
    } // setupUi

    void retranslateUi(QDialog *InsertSudent)
    {
        InsertSudent->setWindowTitle(QApplication::translate("InsertSudent", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("InsertSudent", "Input Surname:", Q_NULLPTR));
        label_7->setText(QApplication::translate("InsertSudent", "Input Name:", Q_NULLPTR));
        label_8->setText(QApplication::translate("InsertSudent", "Input Second name:", Q_NULLPTR));
        label_9->setText(QApplication::translate("InsertSudent", "Input Raiting:", Q_NULLPTR));
        label_10->setText(QApplication::translate("InsertSudent", "Input Role:", Q_NULLPTR));
        m_surname_2->setText(QApplication::translate("InsertSudent", "Somebody", Q_NULLPTR));
        m_name_2->setText(QApplication::translate("InsertSudent", "Once", Q_NULLPTR));
        m_secondName_2->setText(QApplication::translate("InsertSudent", "Toldme", Q_NULLPTR));
        m_raiting_2->setText(QApplication::translate("InsertSudent", "77", Q_NULLPTR));
        m_role_2->setText(QApplication::translate("InsertSudent", "student", Q_NULLPTR));
        m_cancel_2->setText(QApplication::translate("InsertSudent", "Cancel", Q_NULLPTR));
        m_ok_2->setText(QApplication::translate("InsertSudent", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InsertSudent: public Ui_InsertSudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTSUDENT_H
