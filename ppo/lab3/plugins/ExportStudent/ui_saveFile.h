/********************************************************************************
** Form generated from reading UI file 'saveFile.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEFILE_H
#define UI_SAVEFILE_H

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

class Ui_saveFile
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *m_filename;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_cancel;
    QPushButton *m_ok;

    void setupUi(QDialog *saveFile)
    {
        if (saveFile->objectName().isEmpty())
            saveFile->setObjectName(QStringLiteral("saveFile"));
        saveFile->resize(397, 97);
        QFont font;
        font.setPointSize(16);
        saveFile->setFont(font);
        layoutWidget = new QWidget(saveFile);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 80));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        m_filename = new QLineEdit(layoutWidget);
        m_filename->setObjectName(QStringLiteral("m_filename"));

        horizontalLayout->addWidget(m_filename);


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


        retranslateUi(saveFile);

        QMetaObject::connectSlotsByName(saveFile);
    } // setupUi

    void retranslateUi(QDialog *saveFile)
    {
        saveFile->setWindowTitle(QApplication::translate("saveFile", "Add Group", Q_NULLPTR));
        label->setText(QApplication::translate("saveFile", "Save File As", Q_NULLPTR));
        m_filename->setText(QApplication::translate("saveFile", "file1.txt", Q_NULLPTR));
        m_cancel->setText(QApplication::translate("saveFile", "Cancel", Q_NULLPTR));
        m_ok->setText(QApplication::translate("saveFile", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class saveFile: public Ui_saveFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEFILE_H
