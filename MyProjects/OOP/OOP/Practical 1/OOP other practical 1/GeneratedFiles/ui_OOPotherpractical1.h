/********************************************************************************
** Form generated from reading UI file 'OOPotherpractical1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPOTHERPRACTICAL1_H
#define UI_OOPOTHERPRACTICAL1_H

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

class Ui_OOPotherpractical1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOPotherpractical1Class)
    {
        if (OOPotherpractical1Class->objectName().isEmpty())
            OOPotherpractical1Class->setObjectName(QStringLiteral("OOPotherpractical1Class"));
        OOPotherpractical1Class->resize(600, 400);
        menuBar = new QMenuBar(OOPotherpractical1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        OOPotherpractical1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOPotherpractical1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OOPotherpractical1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(OOPotherpractical1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OOPotherpractical1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OOPotherpractical1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OOPotherpractical1Class->setStatusBar(statusBar);

        retranslateUi(OOPotherpractical1Class);

        QMetaObject::connectSlotsByName(OOPotherpractical1Class);
    } // setupUi

    void retranslateUi(QMainWindow *OOPotherpractical1Class)
    {
        OOPotherpractical1Class->setWindowTitle(QApplication::translate("OOPotherpractical1Class", "OOPotherpractical1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPotherpractical1Class: public Ui_OOPotherpractical1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPOTHERPRACTICAL1_H
