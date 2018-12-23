/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

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

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *MovieListLabel;
    QPushButton *UndoButton;
    QPushButton *RedoButton;
    QVBoxLayout *verticalLayout_5;
    QListWidget *MovieList;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *TitleLabel;
    QLabel *GenrLabel;
    QLabel *YearLabel;
    QLabel *LikesLabel;
    QLabel *TrailerLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *TitleLine;
    QLineEdit *GenreLine;
    QLineEdit *YearLine;
    QLineEdit *LikesLine;
    QLineEdit *TrailerLine;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *UpdateButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *UpdateTitleLabel;
    QLineEdit *UpdateTitleLine;
    QLabel *label;
    QLineEdit *FilterLine;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(591, 390);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_6 = new QHBoxLayout(centralwidget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        MovieListLabel = new QLabel(centralwidget);
        MovieListLabel->setObjectName(QStringLiteral("MovieListLabel"));
        QFont font;
        font.setPointSize(10);
        MovieListLabel->setFont(font);

        horizontalLayout_5->addWidget(MovieListLabel);

        UndoButton = new QPushButton(centralwidget);
        UndoButton->setObjectName(QStringLiteral("UndoButton"));

        horizontalLayout_5->addWidget(UndoButton);

        RedoButton = new QPushButton(centralwidget);
        RedoButton->setObjectName(QStringLiteral("RedoButton"));

        horizontalLayout_5->addWidget(RedoButton);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        MovieList = new QListWidget(centralwidget);
        MovieList->setObjectName(QStringLiteral("MovieList"));
        QFont font1;
        font1.setPointSize(11);
        MovieList->setFont(font1);

        verticalLayout_5->addWidget(MovieList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        TitleLabel = new QLabel(centralwidget);
        TitleLabel->setObjectName(QStringLiteral("TitleLabel"));

        verticalLayout->addWidget(TitleLabel);

        GenrLabel = new QLabel(centralwidget);
        GenrLabel->setObjectName(QStringLiteral("GenrLabel"));

        verticalLayout->addWidget(GenrLabel);

        YearLabel = new QLabel(centralwidget);
        YearLabel->setObjectName(QStringLiteral("YearLabel"));

        verticalLayout->addWidget(YearLabel);

        LikesLabel = new QLabel(centralwidget);
        LikesLabel->setObjectName(QStringLiteral("LikesLabel"));

        verticalLayout->addWidget(LikesLabel);

        TrailerLabel = new QLabel(centralwidget);
        TrailerLabel->setObjectName(QStringLiteral("TrailerLabel"));

        verticalLayout->addWidget(TrailerLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        TitleLine = new QLineEdit(centralwidget);
        TitleLine->setObjectName(QStringLiteral("TitleLine"));

        verticalLayout_2->addWidget(TitleLine);

        GenreLine = new QLineEdit(centralwidget);
        GenreLine->setObjectName(QStringLiteral("GenreLine"));

        verticalLayout_2->addWidget(GenreLine);

        YearLine = new QLineEdit(centralwidget);
        YearLine->setObjectName(QStringLiteral("YearLine"));

        verticalLayout_2->addWidget(YearLine);

        LikesLine = new QLineEdit(centralwidget);
        LikesLine->setObjectName(QStringLiteral("LikesLine"));

        verticalLayout_2->addWidget(LikesLine);

        TrailerLine = new QLineEdit(centralwidget);
        TrailerLine->setObjectName(QStringLiteral("TrailerLine"));

        verticalLayout_2->addWidget(TrailerLine);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout_2->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        horizontalLayout_2->addWidget(DeleteButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        UpdateButton = new QPushButton(centralwidget);
        UpdateButton->setObjectName(QStringLiteral("UpdateButton"));

        verticalLayout_3->addWidget(UpdateButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        UpdateTitleLabel = new QLabel(centralwidget);
        UpdateTitleLabel->setObjectName(QStringLiteral("UpdateTitleLabel"));
        UpdateTitleLabel->setFont(font);

        horizontalLayout_3->addWidget(UpdateTitleLabel);

        UpdateTitleLine = new QLineEdit(centralwidget);
        UpdateTitleLine->setObjectName(QStringLiteral("UpdateTitleLine"));

        horizontalLayout_3->addWidget(UpdateTitleLine);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        FilterLine = new QLineEdit(centralwidget);
        FilterLine->setObjectName(QStringLiteral("FilterLine"));

        verticalLayout_4->addWidget(FilterLine);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_6);

        AdminWindow->setCentralWidget(centralwidget);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Admin", nullptr));
        MovieListLabel->setText(QApplication::translate("AdminWindow", "Movie list:                                                                                       ", nullptr));
        UndoButton->setText(QApplication::translate("AdminWindow", "Undo", nullptr));
        RedoButton->setText(QApplication::translate("AdminWindow", "Redo", nullptr));
        TitleLabel->setText(QApplication::translate("AdminWindow", "Title:", nullptr));
        GenrLabel->setText(QApplication::translate("AdminWindow", "Genre:", nullptr));
        YearLabel->setText(QApplication::translate("AdminWindow", "Year:", nullptr));
        LikesLabel->setText(QApplication::translate("AdminWindow", "Likes:", nullptr));
        TrailerLabel->setText(QApplication::translate("AdminWindow", "Trailer:", nullptr));
        AddButton->setText(QApplication::translate("AdminWindow", "Add", nullptr));
        DeleteButton->setText(QApplication::translate("AdminWindow", "Delete", nullptr));
        UpdateButton->setText(QApplication::translate("AdminWindow", "Update", nullptr));
        UpdateTitleLabel->setText(QApplication::translate("AdminWindow", "Update title:", nullptr));
        label->setText(QApplication::translate("AdminWindow", "Type anything to filter:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
