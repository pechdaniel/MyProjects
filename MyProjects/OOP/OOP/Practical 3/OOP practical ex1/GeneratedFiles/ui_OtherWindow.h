/********************************************************************************
** Form generated from reading UI file 'OtherWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHERWINDOW_H
#define UI_OTHERWINDOW_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OtherWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *StudentList;
    QHBoxLayout *horizontalLayout;
    QLineEdit *GradeLine;
    QPushButton *GradeButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OtherWindow)
    {
        if (OtherWindow->objectName().isEmpty())
            OtherWindow->setObjectName(QStringLiteral("OtherWindow"));
        OtherWindow->resize(573, 381);
        centralwidget = new QWidget(OtherWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        StudentList = new QListWidget(centralwidget);
        StudentList->setObjectName(QStringLiteral("StudentList"));

        verticalLayout->addWidget(StudentList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        GradeLine = new QLineEdit(centralwidget);
        GradeLine->setObjectName(QStringLiteral("GradeLine"));

        horizontalLayout->addWidget(GradeLine);

        GradeButton = new QPushButton(centralwidget);
        GradeButton->setObjectName(QStringLiteral("GradeButton"));

        horizontalLayout->addWidget(GradeButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        OtherWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(OtherWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        OtherWindow->setStatusBar(statusbar);

        retranslateUi(OtherWindow);

        QMetaObject::connectSlotsByName(OtherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OtherWindow)
    {
        OtherWindow->setWindowTitle(QApplication::translate("OtherWindow", "TeacherWindow", nullptr));
        label->setText(QApplication::translate("OtherWindow", "Students:", nullptr));
        GradeButton->setText(QApplication::translate("OtherWindow", "Grade", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OtherWindow: public Ui_OtherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHERWINDOW_H
