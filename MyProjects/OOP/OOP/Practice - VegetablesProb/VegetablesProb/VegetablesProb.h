#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VegetablesProb.h"
#include "repository.h"

class VegetablesProb : public QMainWindow
{
	Q_OBJECT

public:
	VegetablesProb(Repository<Vegetable> &r, QWidget *parent = Q_NULLPTR);
	~VegetablesProb() {}
private:
	Ui::VegetablesProbClass ui;
	Repository<Vegetable> &repo;
	vector<Vegetable> list;
	vector<Vegetable> flt;

	void connectSignalsAndSlots();
	void sort();
	void populateFamily();
	void populateVegetable();
	int getSelectedIndex();
	private slots:
	void filter();
};
