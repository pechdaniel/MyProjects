#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AstronomerWindow.h"
#include "controller.h"
#include "astronomer.h"

class AWindow : public QMainWindow
{
	Q_OBJECT

public:
	AWindow(Controller& c, Astronomer a, QWidget *parent = Q_NULLPTR);
	~AWindow() {}

private:
	Ui::AstroWindow ui;

	Controller& contro;
	std::vector<Star> stars;
	Astronomer astro;
	std::vector<Star> filter;
	int ok;
	
	void connectSignalsAndSlots();
	int getSelectedIndex();
	void populate();
	void populateList();

	private slots:
	void add();
	void modify();
	void filterMe();

};
