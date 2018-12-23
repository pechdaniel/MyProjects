/********************************************************************************
** Form generated from reading UI file 'Again12.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGAIN12_H
#define UI_AGAIN12_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Again12Class
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *Again12Class)
    {
        if (Again12Class->objectName().isEmpty())
            Again12Class->setObjectName(QStringLiteral("Again12Class"));
        Again12Class->resize(600, 400);
        centralWidget = new QWidget(Again12Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Again12Class->setCentralWidget(centralWidget);

        retranslateUi(Again12Class);

        QMetaObject::connectSlotsByName(Again12Class);
    } // setupUi

    void retranslateUi(QMainWindow *Again12Class)
    {
        Again12Class->setWindowTitle(QApplication::translate("Again12Class", "Again12", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Again12Class: public Ui_Again12Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGAIN12_H
