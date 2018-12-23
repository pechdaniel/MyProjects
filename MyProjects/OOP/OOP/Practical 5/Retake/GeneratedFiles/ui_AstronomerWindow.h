/********************************************************************************
** Form generated from reading UI file 'AstronomerWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTRONOMERWINDOW_H
#define UI_ASTRONOMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_AstroWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QListWidget *StarsTable;
    QLabel *label_5;
    QListWidget *FilterList;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *NameLine;
    QLineEdit *LuminosityLine;
    QLineEdit *TemperatureLine;
    QPushButton *AddButton;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *FilterLine;

    void setupUi(QMainWindow *AstroWindow)
    {
        if (AstroWindow->objectName().isEmpty())
            AstroWindow->setObjectName(QStringLiteral("AstroWindow"));
        AstroWindow->resize(561, 566);
        centralwidget = new QWidget(AstroWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        StarsTable = new QListWidget(centralwidget);
        StarsTable->setObjectName(QStringLiteral("StarsTable"));

        verticalLayout_3->addWidget(StarsTable);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        FilterList = new QListWidget(centralwidget);
        FilterList->setObjectName(QStringLiteral("FilterList"));

        verticalLayout_3->addWidget(FilterList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        NameLine = new QLineEdit(centralwidget);
        NameLine->setObjectName(QStringLiteral("NameLine"));

        verticalLayout->addWidget(NameLine);

        LuminosityLine = new QLineEdit(centralwidget);
        LuminosityLine->setObjectName(QStringLiteral("LuminosityLine"));

        verticalLayout->addWidget(LuminosityLine);

        TemperatureLine = new QLineEdit(centralwidget);
        TemperatureLine->setObjectName(QStringLiteral("TemperatureLine"));

        verticalLayout->addWidget(TemperatureLine);


        horizontalLayout->addLayout(verticalLayout);

        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout->addWidget(AddButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        FilterLine = new QLineEdit(centralwidget);
        FilterLine->setObjectName(QStringLiteral("FilterLine"));

        horizontalLayout_4->addWidget(FilterLine);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_4);

        AstroWindow->setCentralWidget(centralwidget);

        retranslateUi(AstroWindow);

        QMetaObject::connectSlotsByName(AstroWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AstroWindow)
    {
        AstroWindow->setWindowTitle(QApplication::translate("AstroWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("AstroWindow", "Stars:", nullptr));
        label_5->setText(QApplication::translate("AstroWindow", "Filtered:", nullptr));
        label_2->setText(QApplication::translate("AstroWindow", "Name:", nullptr));
        label_3->setText(QApplication::translate("AstroWindow", "Luminosity:", nullptr));
        label_4->setText(QApplication::translate("AstroWindow", "Temperature:", nullptr));
        AddButton->setText(QApplication::translate("AstroWindow", "Add", nullptr));
        checkBox->setText(QApplication::translate("AstroWindow", "Filter by constellation", nullptr));
        label_6->setText(QApplication::translate("AstroWindow", "Search for", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AstroWindow: public Ui_AstroWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTRONOMERWINDOW_H
