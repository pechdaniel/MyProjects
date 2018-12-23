/********************************************************************************
** Form generated from reading UI file 'Vegetables.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEGETABLES_H
#define UI_VEGETABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VegetablesWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *FamilyList;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QListWidget *VegetableList;

    void setupUi(QMainWindow *VegetablesWindow)
    {
        if (VegetablesWindow->objectName().isEmpty())
            VegetablesWindow->setObjectName(QStringLiteral("VegetablesWindow"));
        VegetablesWindow->resize(552, 282);
        centralWidget = new QWidget(VegetablesWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        FamilyList = new QListWidget(centralWidget);
        FamilyList->setObjectName(QStringLiteral("FamilyList"));

        verticalLayout->addWidget(FamilyList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        VegetableList = new QListWidget(centralWidget);
        VegetableList->setObjectName(QStringLiteral("VegetableList"));

        verticalLayout->addWidget(VegetableList);


        horizontalLayout_2->addLayout(verticalLayout);

        VegetablesWindow->setCentralWidget(centralWidget);

        retranslateUi(VegetablesWindow);

        QMetaObject::connectSlotsByName(VegetablesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VegetablesWindow)
    {
        VegetablesWindow->setWindowTitle(QApplication::translate("VegetablesWindow", "Veggies", nullptr));
        label_2->setText(QApplication::translate("VegetablesWindow", "Family list:", nullptr));
        pushButton->setText(QApplication::translate("VegetablesWindow", "Search", nullptr));
        label->setText(QApplication::translate("VegetablesWindow", "Vegetables list:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VegetablesWindow: public Ui_VegetablesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEGETABLES_H
