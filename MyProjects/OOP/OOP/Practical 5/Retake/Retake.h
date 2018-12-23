#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Retake.h"

class Retake : public QMainWindow
{
	Q_OBJECT

public:
	Retake(QWidget *parent = Q_NULLPTR);

private:
	Ui::RetakeClass ui;
};
