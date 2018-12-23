#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Time.h"
#include "repository.h"
#include "domain.h"

class Time : public QMainWindow
{
	Q_OBJECT

public:
	Time(Repository<Task> &r,QWidget *parent = Q_NULLPTR);

private:
	Ui::TimeClass ui;
	Repository<Task> &repo;

	void connectSignalsAndSlots();
	void populate();
	void sort();
	void blodIt();
	private slots:
	void showDuration();
};
