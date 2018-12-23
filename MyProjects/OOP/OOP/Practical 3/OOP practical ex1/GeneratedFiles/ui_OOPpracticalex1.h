/********************************************************************************
** Form generated from reading UI file 'OOPpracticalex1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPPRACTICALEX1_H
#define UI_OOPPRACTICALEX1_H

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

class Ui_OOPpracticalex1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOPpracticalex1Class)
    {
        if (OOPpracticalex1Class->objectName().isEmpty())
            OOPpracticalex1Class->setObjectName(QStringLiteral("OOPpracticalex1Class"));
        OOPpracticalex1Class->resize(600, 400);
        menuBar = new QMenuBar(OOPpracticalex1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        OOPpracticalex1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOPpracticalex1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OOPpracticalex1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(OOPpracticalex1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OOPpracticalex1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OOPpracticalex1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OOPpracticalex1Class->setStatusBar(statusBar);

        retranslateUi(OOPpracticalex1Class);

        QMetaObject::connectSlotsByName(OOPpracticalex1Class);
    } // setupUi

    void retranslateUi(QMainWindow *OOPpracticalex1Class)
    {
        OOPpracticalex1Class->setWindowTitle(QApplication::translate("OOPpracticalex1Class", "OOPpracticalex1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPpracticalex1Class: public Ui_OOPpracticalex1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPPRACTICALEX1_H
