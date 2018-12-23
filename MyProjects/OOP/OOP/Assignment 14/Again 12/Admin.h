#pragma once

#include <QtWidgets\QMainWindow>
#include "ui_admin.h"
#include "controller.h"
#include "repository.h"
#include "movie.h"
#include "operation.h"
#include "redo.h"
#include "undo.h"

class Admin :public QMainWindow
{
	Q_OBJECT

public:
	Admin(Repository r,QWidget *parent = Q_NULLPTR);
	~Admin();
	void readFromFile();
private:
	Repository repo;
	Repository flt;
	Ui::AdminWindow ui;
	Operation* und;
	Operation* red;


	void populate();
	int getSelectedIndex();
	private slots:
	void connectSignalsAndSlots();
	void add();
	void del();
	void update();
	void filter();
	void undoFcT();
	void redoFcT();
};