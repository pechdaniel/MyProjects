/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *PasswordWindow)
    {
        if (PasswordWindow->objectName().isEmpty())
            PasswordWindow->setObjectName(QStringLiteral("PasswordWindow"));
        PasswordWindow->resize(334, 64);
        centralwidget = new QWidget(PasswordWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 30, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 191, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        PasswordWindow->setCentralWidget(centralwidget);

        retranslateUi(PasswordWindow);

        QMetaObject::connectSlotsByName(PasswordWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PasswordWindow)
    {
        PasswordWindow->setWindowTitle(QApplication::translate("PasswordWindow", "Password", nullptr));
        pushButton->setText(QApplication::translate("PasswordWindow", "Log in", nullptr));
        label->setText(QApplication::translate("PasswordWindow", "Enter the password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordWindow: public Ui_PasswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
