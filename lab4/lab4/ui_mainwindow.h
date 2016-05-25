/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *start_lift_box;
    QGridLayout *gridLayout;
    QPushButton *floor3BTN;
    QPushButton *floor2BTN;
    QPushButton *floor1BTN;
    QPushButton *floor4BTN;
    QPushButton *floor5BTN;
    QPushButton *floor6BTN;
    QPushButton *floor7BTN;
    QGroupBox *lift_floor_box;
    QVBoxLayout *verticalLayout;
    QPushButton *floor1BTN_2;
    QPushButton *floor2BTN_2;
    QPushButton *floor3BTN_2;
    QPushButton *floor4BTN_2;
    QPushButton *floor5BTN_2;
    QPushButton *floor6BTN_2;
    QPushButton *floor7BTN_2;
    QLCDNumber *lcdNumber;
    QLineEdit *lift_state;
    QLabel *state_label;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(241, 413);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        start_lift_box = new QGroupBox(centralWidget);
        start_lift_box->setObjectName(QStringLiteral("start_lift_box"));
        start_lift_box->setGeometry(QRect(4, 71, 111, 291));
        gridLayout = new QGridLayout(start_lift_box);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        floor3BTN = new QPushButton(start_lift_box);
        floor3BTN->setObjectName(QStringLiteral("floor3BTN"));

        gridLayout->addWidget(floor3BTN, 2, 0, 1, 1);

        floor2BTN = new QPushButton(start_lift_box);
        floor2BTN->setObjectName(QStringLiteral("floor2BTN"));

        gridLayout->addWidget(floor2BTN, 1, 0, 1, 1);

        floor1BTN = new QPushButton(start_lift_box);
        floor1BTN->setObjectName(QStringLiteral("floor1BTN"));
        floor1BTN->setFlat(false);

        gridLayout->addWidget(floor1BTN, 0, 0, 1, 1);

        floor4BTN = new QPushButton(start_lift_box);
        floor4BTN->setObjectName(QStringLiteral("floor4BTN"));

        gridLayout->addWidget(floor4BTN, 3, 0, 1, 1);

        floor5BTN = new QPushButton(start_lift_box);
        floor5BTN->setObjectName(QStringLiteral("floor5BTN"));

        gridLayout->addWidget(floor5BTN, 4, 0, 1, 1);

        floor6BTN = new QPushButton(start_lift_box);
        floor6BTN->setObjectName(QStringLiteral("floor6BTN"));

        gridLayout->addWidget(floor6BTN, 5, 0, 1, 1);

        floor7BTN = new QPushButton(start_lift_box);
        floor7BTN->setObjectName(QStringLiteral("floor7BTN"));

        gridLayout->addWidget(floor7BTN, 6, 0, 1, 1);

        lift_floor_box = new QGroupBox(centralWidget);
        lift_floor_box->setObjectName(QStringLiteral("lift_floor_box"));
        lift_floor_box->setGeometry(QRect(120, 70, 111, 291));
        verticalLayout = new QVBoxLayout(lift_floor_box);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        floor1BTN_2 = new QPushButton(lift_floor_box);
        floor1BTN_2->setObjectName(QStringLiteral("floor1BTN_2"));
        floor1BTN_2->setFlat(false);

        verticalLayout->addWidget(floor1BTN_2);

        floor2BTN_2 = new QPushButton(lift_floor_box);
        floor2BTN_2->setObjectName(QStringLiteral("floor2BTN_2"));

        verticalLayout->addWidget(floor2BTN_2);

        floor3BTN_2 = new QPushButton(lift_floor_box);
        floor3BTN_2->setObjectName(QStringLiteral("floor3BTN_2"));

        verticalLayout->addWidget(floor3BTN_2);

        floor4BTN_2 = new QPushButton(lift_floor_box);
        floor4BTN_2->setObjectName(QStringLiteral("floor4BTN_2"));

        verticalLayout->addWidget(floor4BTN_2);

        floor5BTN_2 = new QPushButton(lift_floor_box);
        floor5BTN_2->setObjectName(QStringLiteral("floor5BTN_2"));

        verticalLayout->addWidget(floor5BTN_2);

        floor6BTN_2 = new QPushButton(lift_floor_box);
        floor6BTN_2->setObjectName(QStringLiteral("floor6BTN_2"));

        verticalLayout->addWidget(floor6BTN_2);

        floor7BTN_2 = new QPushButton(lift_floor_box);
        floor7BTN_2->setObjectName(QStringLiteral("floor7BTN_2"));

        verticalLayout->addWidget(floor7BTN_2);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(10, 10, 81, 41));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(1));
        lift_state = new QLineEdit(centralWidget);
        lift_state->setObjectName(QStringLiteral("lift_state"));
        lift_state->setGeometry(QRect(120, 20, 113, 20));
        lift_state->setReadOnly(true);
        state_label = new QLabel(centralWidget);
        state_label->setObjectName(QStringLiteral("state_label"));
        state_label->setGeometry(QRect(120, 0, 47, 13));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 60, 221, 20));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 241, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        floor1BTN->setDefault(false);
        floor1BTN_2->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        start_lift_box->setTitle(QApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266\320\270", 0));
        floor3BTN->setText(QApplication::translate("MainWindow", "3", 0));
        floor2BTN->setText(QApplication::translate("MainWindow", "2", 0));
        floor1BTN->setText(QApplication::translate("MainWindow", "1", 0));
        floor4BTN->setText(QApplication::translate("MainWindow", "4", 0));
        floor5BTN->setText(QApplication::translate("MainWindow", "5", 0));
        floor6BTN->setText(QApplication::translate("MainWindow", "6", 0));
        floor7BTN->setText(QApplication::translate("MainWindow", "7", 0));
        lift_floor_box->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\215\321\202\320\260\320\266\320\260", 0));
        floor1BTN_2->setText(QApplication::translate("MainWindow", "1", 0));
        floor2BTN_2->setText(QApplication::translate("MainWindow", "2", 0));
        floor3BTN_2->setText(QApplication::translate("MainWindow", "3", 0));
        floor4BTN_2->setText(QApplication::translate("MainWindow", "4", 0));
        floor5BTN_2->setText(QApplication::translate("MainWindow", "5", 0));
        floor6BTN_2->setText(QApplication::translate("MainWindow", "6", 0));
        floor7BTN_2->setText(QApplication::translate("MainWindow", "7", 0));
        state_label->setText(QApplication::translate("MainWindow", "State", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
