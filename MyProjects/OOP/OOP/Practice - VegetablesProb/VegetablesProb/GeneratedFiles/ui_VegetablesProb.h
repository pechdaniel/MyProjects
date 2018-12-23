/********************************************************************************
** Form generated from reading UI file 'VegetablesProb.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEGETABLESPROB_H
#define UI_VEGETABLESPROB_H

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

class Ui_VegetablesProbClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *FamilyList;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QListWidget *VegetableList;

    void setupUi(QMainWindow *VegetablesProbClass)
    {
        if (VegetablesProbClass->objectName().isEmpty())
            VegetablesProbClass->setObjectName(QStringLiteral("VegetablesProbClass"));
        VegetablesProbClass->resize(600, 400);
        centralWidget = new QWidget(VegetablesProbClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

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

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        VegetableList = new QListWidget(centralWidget);
        VegetableList->setObjectName(QStringLiteral("VegetableList"));

        verticalLayout->addWidget(VegetableList);


        horizontalLayout_2->addLayout(verticalLayout);

        VegetablesProbClass->setCentralWidget(centralWidget);

        retranslateUi(VegetablesProbClass);

        QMetaObject::connectSlotsByName(VegetablesProbClass);
    } // setupUi

    void retranslateUi(QMainWindow *VegetablesProbClass)
    {
        VegetablesProbClass->setWindowTitle(QApplication::translate("VegetablesProbClass", "VegetablesProb", nullptr));
        label->setText(QApplication::translate("VegetablesProbClass", "Family list:", nullptr));
        pushButton->setText(QApplication::translate("VegetablesProbClass", "Search", nullptr));
        label_2->setText(QApplication::translate("VegetablesProbClass", "Vegetable list:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VegetablesProbClass: public Ui_VegetablesProbClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEGETABLESPROB_H
