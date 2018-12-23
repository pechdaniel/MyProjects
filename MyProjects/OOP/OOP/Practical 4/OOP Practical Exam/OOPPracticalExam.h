#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPPracticalExam.h"

class OOPPracticalExam : public QMainWindow
{
	Q_OBJECT

public:
	OOPPracticalExam(QWidget *parent = Q_NULLPTR);

private:
	Ui::OOPPracticalExamClass ui;
};
