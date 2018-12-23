#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPPracticalex.h"

class OOPPracticalex : public QMainWindow
{
	Q_OBJECT

public:
	OOPPracticalex(QWidget *parent = Q_NULLPTR);

private:
	Ui::OOPPracticalexClass ui;
};
