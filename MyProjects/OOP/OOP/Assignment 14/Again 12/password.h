#pragma once
#include "ui_password.h"
#include <QtWidgets\QMainWindow>
#include <Admin.h>

class Password :public QMainWindow
{
	Q_OBJECT
public:
	Password(Admin &a, QMainWindow *parent=Q_NULLPTR);
	~Password() {}
	void readFromFile() { this->admin.readFromFile(); }
private:
	Ui::PasswordWindow ui;
	Admin& admin;
	std::string password;

	private slots:
	void connectSignalsAndSlots();
	void checkAndShow();
};