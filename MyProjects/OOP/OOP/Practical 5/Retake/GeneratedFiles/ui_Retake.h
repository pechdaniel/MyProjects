/********************************************************************************
** Form generated from reading UI file 'Retake.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETAKE_H
#define UI_RETAKE_H

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

class Ui_RetakeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RetakeClass)
    {
        if (RetakeClass->objectName().isEmpty())
            RetakeClass->setObjectName(QStringLiteral("RetakeClass"));
        RetakeClass->resize(600, 400);
        menuBar = new QMenuBar(RetakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RetakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RetakeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RetakeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RetakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RetakeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RetakeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RetakeClass->setStatusBar(statusBar);

        retranslateUi(RetakeClass);

        QMetaObject::connectSlotsByName(RetakeClass);
    } // setupUi

    void retranslateUi(QMainWindow *RetakeClass)
    {
        RetakeClass->setWindowTitle(QApplication::translate("RetakeClass", "Retake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RetakeClass: public Ui_RetakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETAKE_H
