/********************************************************************************
** Form generated from reading UI file 'OOPPracticalex.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPPRACTICALEX_H
#define UI_OOPPRACTICALEX_H

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

class Ui_OOPPracticalexClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOPPracticalexClass)
    {
        if (OOPPracticalexClass->objectName().isEmpty())
            OOPPracticalexClass->setObjectName(QStringLiteral("OOPPracticalexClass"));
        OOPPracticalexClass->resize(600, 400);
        menuBar = new QMenuBar(OOPPracticalexClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        OOPPracticalexClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOPPracticalexClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OOPPracticalexClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OOPPracticalexClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OOPPracticalexClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OOPPracticalexClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OOPPracticalexClass->setStatusBar(statusBar);

        retranslateUi(OOPPracticalexClass);

        QMetaObject::connectSlotsByName(OOPPracticalexClass);
    } // setupUi

    void retranslateUi(QMainWindow *OOPPracticalexClass)
    {
        OOPPracticalexClass->setWindowTitle(QApplication::translate("OOPPracticalexClass", "OOPPracticalex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPPracticalexClass: public Ui_OOPPracticalexClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPPRACTICALEX_H
