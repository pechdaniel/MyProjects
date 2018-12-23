#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Vegetables.h"
#include "repository.h"

class Vegetables : public QMainWindow
{
	Q_OBJECT

public:
	Vegetables(Repository &r,QWidget *parent = Q_NULLPTR);
	~Vegetables() {}
private:
	Ui::VegetablesWindow ui;
	Repository &repo;
	Repository flt;

	
	void populateFam();
	void populateVeg();
	int getSelectedIndex();
	void sort();
	private slots:
	void connectSignalsAndSlots();
	void filterR();
};
