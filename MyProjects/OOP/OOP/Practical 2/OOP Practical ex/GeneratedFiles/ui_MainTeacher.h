/********************************************************************************
** Form generated from reading UI file 'MainTeacher.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTEACHER_H
#define UI_MAINTEACHER_H

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

class Ui_MainTeacher
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *NameLine;
    QLineEdit *GroupLine;
    QVBoxLayout *verticalLayout_3;
    QPushButton *AddButton;
    QPushButton *DeleteButton;

    void setupUi(QMainWindow *MainTeacher)
    {
        if (MainTeacher->objectName().isEmpty())
            MainTeacher->setObjectName(QStringLiteral("MainTeacher"));
        MainTeacher->resize(598, 279);
        centralwidget = new QWidget(MainTeacher);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_4->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        NameLine = new QLineEdit(centralwidget);
        NameLine->setObjectName(QStringLiteral("NameLine"));

        verticalLayout->addWidget(NameLine);

        GroupLine = new QLineEdit(centralwidget);
        GroupLine->setObjectName(QStringLiteral("GroupLine"));

        verticalLayout->addWidget(GroupLine);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        verticalLayout_3->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        verticalLayout_3->addWidget(DeleteButton);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        MainTeacher->setCentralWidget(centralwidget);

        retranslateUi(MainTeacher);

        QMetaObject::connectSlotsByName(MainTeacher);
    } // setupUi

    void retranslateUi(QMainWindow *MainTeacher)
    {
        MainTeacher->setWindowTitle(QApplication::translate("MainTeacher", "Main Teacher", nullptr));
        label->setText(QApplication::translate("MainTeacher", "Students:", nullptr));
        label_2->setText(QApplication::translate("MainTeacher", "Name:", nullptr));
        label_3->setText(QApplication::translate("MainTeacher", "Group:", nullptr));
        AddButton->setText(QApplication::translate("MainTeacher", "Add", nullptr));
        DeleteButton->setText(QApplication::translate("MainTeacher", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainTeacher: public Ui_MainTeacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTEACHER_H
