/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *MovieList;
    QHBoxLayout *horizontalLayout_2;
    QTableView *MovieTable;
    QWidget *WatchList;
    QHBoxLayout *horizontalLayout_3;
    QTableView *WatchTable;

    void setupUi(QMainWindow *ViewWindow)
    {
        if (ViewWindow->objectName().isEmpty())
            ViewWindow->setObjectName(QStringLiteral("ViewWindow"));
        ViewWindow->resize(605, 369);
        centralwidget = new QWidget(ViewWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        MovieList = new QWidget();
        MovieList->setObjectName(QStringLiteral("MovieList"));
        horizontalLayout_2 = new QHBoxLayout(MovieList);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        MovieTable = new QTableView(MovieList);
        MovieTable->setObjectName(QStringLiteral("MovieTable"));

        horizontalLayout_2->addWidget(MovieTable);

        tabWidget->addTab(MovieList, QString());
        WatchList = new QWidget();
        WatchList->setObjectName(QStringLiteral("WatchList"));
        horizontalLayout_3 = new QHBoxLayout(WatchList);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        WatchTable = new QTableView(WatchList);
        WatchTable->setObjectName(QStringLiteral("WatchTable"));

        horizontalLayout_3->addWidget(WatchTable);

        tabWidget->addTab(WatchList, QString());

        horizontalLayout->addWidget(tabWidget);

        ViewWindow->setCentralWidget(centralwidget);

        retranslateUi(ViewWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ViewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewWindow)
    {
        ViewWindow->setWindowTitle(QApplication::translate("ViewWindow", "View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MovieList), QApplication::translate("ViewWindow", "Movie list", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(WatchList), QApplication::translate("ViewWindow", "Watch list", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewWindow: public Ui_ViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
