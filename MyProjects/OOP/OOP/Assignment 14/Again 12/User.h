#pragma once

#include <QtWidgets\QMainWindow>
#include "ui_user.h"
#include "controller.h"
#include "operation.h"
#include "redo.h"
#include "undo.h"

class User :public QMainWindow
{
	Q_OBJECT

public:
	User(Controller c,QWidget *parrent = Q_NULLPTR);
	~User();
	Repository getRepo() { return contro.getAll(); }
	Repository getList() { return contro.getList(); }
	void readFromFile();
private:
	Ui::UserWindow ui;
	Controller contro;
	Repository filter{};
	Operation* und;
	Operation* red;
	int lastDeleted;

	int getSelectedIndex();
	void connectSignalsAndSlots();
	void populateWatchList();
	void populateFilter();
	private slots:
	void filterMovies();
	void addMovie();
	void delMovie();
	void likeMovie();
	void showCSV();
	void showHTML();
	void nextMovie();
	void undoFct();
	void redoFct();
};