/********************************************************************************
** Form generated from reading UI file 'Time.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIME_H
#define UI_TIME_H

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

class Ui_TimeClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QLabel *ShowLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *TimeClass)
    {
        if (TimeClass->objectName().isEmpty())
            TimeClass->setObjectName(QStringLiteral("TimeClass"));
        TimeClass->resize(599, 394);
        centralWidget = new QWidget(TimeClass);
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

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        ShowLabel = new QLabel(centralWidget);
        ShowLabel->setObjectName(QStringLiteral("ShowLabel"));

        verticalLayout->addWidget(ShowLabel);

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


        horizontalLayout_2->addLayout(verticalLayout);

        TimeClass->setCentralWidget(centralWidget);

        retranslateUi(TimeClass);

        QMetaObject::connectSlotsByName(TimeClass);
    } // setupUi

    void retranslateUi(QMainWindow *TimeClass)
    {
        TimeClass->setWindowTitle(QApplication::translate("TimeClass", "Time", nullptr));
        label->setText(QApplication::translate("TimeClass", "Tasks:", nullptr));
        ShowLabel->setText(QString());
        pushButton->setText(QApplication::translate("TimeClass", "Show duration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeClass: public Ui_TimeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIME_H
