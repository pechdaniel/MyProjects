/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *NextButton;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *FilterButton;
    QListWidget *FilteredList;
    QPushButton *LikeButton;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ShowCSVButton;
    QPushButton *ShowHTMLButton;
    QLabel *MovieListLabel;
    QLabel *FilteredLabel;
    QLineEdit *FilterByTitleLine;
    QLabel *FilterLabel;
    QListWidget *MovieList;
    QPushButton *UndoButton;
    QPushButton *RedoButton;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QStringLiteral("UserWindow"));
        UserWindow->resize(591, 510);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(310, 390, 239, 48));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NextButton = new QPushButton(layoutWidget);
        NextButton->setObjectName(QStringLiteral("NextButton"));

        horizontalLayout->addWidget(NextButton);

        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(layoutWidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);

        splitter->addWidget(layoutWidget);
        FilterButton = new QPushButton(splitter);
        FilterButton->setObjectName(QStringLiteral("FilterButton"));
        splitter->addWidget(FilterButton);
        FilteredList = new QListWidget(centralwidget);
        FilteredList->setObjectName(QStringLiteral("FilteredList"));
        FilteredList->setGeometry(QRect(10, 220, 571, 141));
        LikeButton = new QPushButton(centralwidget);
        LikeButton->setObjectName(QStringLiteral("LikeButton"));
        LikeButton->setGeometry(QRect(240, 450, 75, 23));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(420, 480, 163, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ShowCSVButton = new QPushButton(layoutWidget_2);
        ShowCSVButton->setObjectName(QStringLiteral("ShowCSVButton"));

        horizontalLayout_2->addWidget(ShowCSVButton);

        ShowHTMLButton = new QPushButton(layoutWidget_2);
        ShowHTMLButton->setObjectName(QStringLiteral("ShowHTMLButton"));

        horizontalLayout_2->addWidget(ShowHTMLButton);

        MovieListLabel = new QLabel(centralwidget);
        MovieListLabel->setObjectName(QStringLiteral("MovieListLabel"));
        MovieListLabel->setGeometry(QRect(10, 20, 61, 16));
        QFont font;
        font.setPointSize(10);
        MovieListLabel->setFont(font);
        FilteredLabel = new QLabel(centralwidget);
        FilteredLabel->setObjectName(QStringLiteral("FilteredLabel"));
        FilteredLabel->setGeometry(QRect(10, 200, 71, 16));
        FilteredLabel->setFont(font);
        FilterByTitleLine = new QLineEdit(centralwidget);
        FilterByTitleLine->setObjectName(QStringLiteral("FilterByTitleLine"));
        FilterByTitleLine->setGeometry(QRect(50, 410, 191, 20));
        FilterLabel = new QLabel(centralwidget);
        FilterLabel->setObjectName(QStringLiteral("FilterLabel"));
        FilterLabel->setGeometry(QRect(50, 390, 201, 16));
        FilterLabel->setFont(font);
        MovieList = new QListWidget(centralwidget);
        MovieList->setObjectName(QStringLiteral("MovieList"));
        MovieList->setGeometry(QRect(10, 40, 571, 151));
        UndoButton = new QPushButton(centralwidget);
        UndoButton->setObjectName(QStringLiteral("UndoButton"));
        UndoButton->setGeometry(QRect(420, 10, 75, 23));
        RedoButton = new QPushButton(centralwidget);
        RedoButton->setObjectName(QStringLiteral("RedoButton"));
        RedoButton->setGeometry(QRect(500, 10, 75, 23));
        UserWindow->setCentralWidget(centralwidget);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "User", nullptr));
        NextButton->setText(QApplication::translate("UserWindow", "Next >>", nullptr));
        AddButton->setText(QApplication::translate("UserWindow", "Add", nullptr));
        DeleteButton->setText(QApplication::translate("UserWindow", "Delete", nullptr));
        FilterButton->setText(QApplication::translate("UserWindow", "Filter", nullptr));
        LikeButton->setText(QApplication::translate("UserWindow", "Like", nullptr));
        ShowCSVButton->setText(QApplication::translate("UserWindow", "Show CSV file", nullptr));
        ShowHTMLButton->setText(QApplication::translate("UserWindow", "Show HTML file", nullptr));
        MovieListLabel->setText(QApplication::translate("UserWindow", "Movie list:", nullptr));
        FilteredLabel->setText(QApplication::translate("UserWindow", "Filtered list:", nullptr));
        FilterLabel->setText(QApplication::translate("UserWindow", "Filter by genre (\"empty\" to get all):", nullptr));
        UndoButton->setText(QApplication::translate("UserWindow", "Undo", nullptr));
        RedoButton->setText(QApplication::translate("UserWindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
