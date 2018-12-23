#pragma once
#include "ui_ProgrammerWindow.h"
#include <QtWidgets\QMainWindow>
#include "controller.h"
#include <vector>

class ProgrammerWindow : public QMainWindow
{
	Q_OBJECT

public:
	ProgrammerWindow(Controller& c, Programmer p, std::vector<ProgrammerWindow*> v, QWidget *parent = Q_NULLPTR);
	ProgrammerWindow(Controller& c, Programmer p, QWidget *parent = Q_NULLPTR);
	ProgrammerWindow(QWidget *parent = Q_NULLPTR);
	~ProgrammerWindow();
	void populate();
	void showIt();

	void setContro(Controller& c) { controller = c; }
	void setProg(Programmer p) { prog = p; }
	void setAll(std::vector<ProgrammerWindow*> v) { allWindows = v; }
private:
	Ui::MyWindow ui;
	Controller& controller;
	Programmer prog;
	std::vector<ProgrammerWindow*> allWindows;

	void connectSignalsAndSlots();
	int getSelectedIndex();
	void modifyAll();

	private slots:
	void add();
	void start();
	void done();
	void del();
	void checkDel();
};