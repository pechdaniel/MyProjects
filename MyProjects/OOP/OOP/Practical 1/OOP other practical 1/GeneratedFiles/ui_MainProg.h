/********************************************************************************
** Form generated from reading UI file 'MainProg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPROG_H
#define UI_MAINPROG_H

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

class Ui_HeadProg
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *TaskList;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *TaskLine;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *StartButton;
    QPushButton *DoneButton;

    void setupUi(QMainWindow *HeadProg)
    {
        if (HeadProg->objectName().isEmpty())
            HeadProg->setObjectName(QStringLiteral("HeadProg"));
        HeadProg->resize(596, 379);
        centralwidget = new QWidget(HeadProg);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        TaskList = new QListWidget(centralwidget);
        TaskList->setObjectName(QStringLiteral("TaskList"));

        verticalLayout_2->addWidget(TaskList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        TaskLine = new QLineEdit(centralwidget);
        TaskLine->setObjectName(QStringLiteral("TaskLine"));

        horizontalLayout_3->addWidget(TaskLine);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout_2->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        horizontalLayout_2->addWidget(DeleteButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        StartButton = new QPushButton(centralwidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));

        horizontalLayout->addWidget(StartButton);

        DoneButton = new QPushButton(centralwidget);
        DoneButton->setObjectName(QStringLiteral("DoneButton"));

        horizontalLayout->addWidget(DoneButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        HeadProg->setCentralWidget(centralwidget);

        retranslateUi(HeadProg);

        QMetaObject::connectSlotsByName(HeadProg);
    } // setupUi

    void retranslateUi(QMainWindow *HeadProg)
    {
        HeadProg->setWindowTitle(QApplication::translate("HeadProg", "HeadProg", nullptr));
        label->setText(QApplication::translate("HeadProg", "Tasks:", nullptr));
        label_2->setText(QApplication::translate("HeadProg", "Description:", nullptr));
        AddButton->setText(QApplication::translate("HeadProg", "Add", nullptr));
        DeleteButton->setText(QApplication::translate("HeadProg", "Delete", nullptr));
        StartButton->setText(QApplication::translate("HeadProg", "Start", nullptr));
        DoneButton->setText(QApplication::translate("HeadProg", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeadProg: public Ui_HeadProg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPROG_H
