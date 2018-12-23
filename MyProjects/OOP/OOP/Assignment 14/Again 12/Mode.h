#pragma once

#include <QtWidgets\QMainWindow>
#include "ui_mode.h"
#include "controller.h"
#include "Admin.h"
#include "User.h"
#include "password.h"
#include "view.h"
#include "table.h"

class Mode :public QMainWindow
{
	Q_OBJECT

public:
	Mode(Admin &a,User &u,Repository &r,Repository &l, QWidget *parent = Q_NULLPTR);
	~Mode() { delete this->table; }
private:
	Ui::ModeWindow ui;
	Admin *adm;
	User *usr;
	View *table;
	Repository &r;
	Repository &l;
	Password password;

	void connectSignalsAndSlots();
	void setAdmin(Admin &a);
	void setUser(User &u);
	private slots:
	void AdminMode();
	void UserMode();
	void passwordShow();
	void viewAll();
};