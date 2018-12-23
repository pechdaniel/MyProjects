#pragma once
#include "ui_view.h"
#include <QtWidgets\QMainWindow>
#include "repository.h"
#include "table.h"

class View :public QMainWindow
{
	Q_OBJECT
private:
	Repository & repo;
	Repository & list;
	MovieTable* mTable;
	MovieTable* wTable;
	Ui::ViewWindow ui;

public:
	View(Repository &r,Repository &l, QWidget *parent = Q_NULLPTR);
	~View();
private:
	void setupTableView();
	void setupTableView1();
};