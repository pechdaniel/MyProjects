/********************************************************************************
** Form generated from reading UI file 'mode.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_H
#define UI_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModeWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *QuestionLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *UserButton;
    QPushButton *AdminButton;
    QPushButton *ViewButton;

    void setupUi(QMainWindow *ModeWindow)
    {
        if (ModeWindow->objectName().isEmpty())
            ModeWindow->setObjectName(QStringLiteral("ModeWindow"));
        ModeWindow->resize(382, 97);
        centralwidget = new QWidget(ModeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        QuestionLabel = new QLabel(centralwidget);
        QuestionLabel->setObjectName(QStringLiteral("QuestionLabel"));
        QFont font;
        font.setPointSize(12);
        QuestionLabel->setFont(font);

        verticalLayout->addWidget(QuestionLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UserButton = new QPushButton(centralwidget);
        UserButton->setObjectName(QStringLiteral("UserButton"));

        horizontalLayout->addWidget(UserButton);

        AdminButton = new QPushButton(centralwidget);
        AdminButton->setObjectName(QStringLiteral("AdminButton"));

        horizontalLayout->addWidget(AdminButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        ViewButton = new QPushButton(centralwidget);
        ViewButton->setObjectName(QStringLiteral("ViewButton"));

        verticalLayout_2->addWidget(ViewButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        ModeWindow->setCentralWidget(centralwidget);

        retranslateUi(ModeWindow);

        QMetaObject::connectSlotsByName(ModeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ModeWindow)
    {
        ModeWindow->setWindowTitle(QApplication::translate("ModeWindow", "Mode", nullptr));
        QuestionLabel->setText(QApplication::translate("ModeWindow", "Do you want to continue as an admin or as a user?", nullptr));
        UserButton->setText(QApplication::translate("ModeWindow", "User", nullptr));
        AdminButton->setText(QApplication::translate("ModeWindow", "Admin", nullptr));
        ViewButton->setText(QApplication::translate("ModeWindow", "Neither, I just want to see the lists of movies.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModeWindow: public Ui_ModeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_H
