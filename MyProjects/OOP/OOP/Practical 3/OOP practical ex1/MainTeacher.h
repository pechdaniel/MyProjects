#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HeadWindow.h"
#include "SomeTeacher.h"
#include "controller.h"
#include <vector>

class MainTeacher : public QMainWindow
{
	Q_OBJECT

public:
	MainTeacher(Controller& c,QWidget *parent = Q_NULLPTR);
	~MainTeacher();
private:
	Ui::HeadWindow ui;
	Controller& controller;
	std::vector<SomeTeacher*> allWindows;

	void populate();
	void connectSignalsAndSlots();
	void modifyAll();
	void showAll();
	int getSelectedIndex();

	private slots:
	void add();
	void del();
};
