/********************************************************************************
** Form generated from reading UI file 'lab11.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11_H
#define UI_LAB11_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab11Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab11Class)
    {
        if (Lab11Class->objectName().isEmpty())
            Lab11Class->setObjectName(QStringLiteral("Lab11Class"));
        Lab11Class->resize(600, 400);
        menuBar = new QMenuBar(Lab11Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab11Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab11Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab11Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab11Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab11Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab11Class->setStatusBar(statusBar);

        retranslateUi(Lab11Class);

        QMetaObject::connectSlotsByName(Lab11Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab11Class)
    {
        Lab11Class->setWindowTitle(QApplication::translate("Lab11Class", "Lab11", 0));
    } // retranslateUi

};

namespace Ui {
    class Lab11Class: public Ui_Lab11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11_H
