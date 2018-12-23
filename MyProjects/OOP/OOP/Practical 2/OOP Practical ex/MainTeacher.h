#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainTeacher.h"
#include "controller.h"
#include "TeacherWindow.h"

class HeadTeacher : public QMainWindow
{
	Q_OBJECT

public:
	HeadTeacher(Controller& c,QWidget *parent = Q_NULLPTR);
	~HeadTeacher() {}
private:
	Controller & controller;
	Ui::MainTeacher ui;
	std::vector<SepareteTeacher*> all;
	int currentID;

	void connectSignalsAndSlots();
	int getSelectedIndex();
	void populate();
	void modifyAll();
	void showAll();
	private slots:
	void add();
	void del();
};
