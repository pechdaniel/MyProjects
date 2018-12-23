#include "password.h"
#include <QMessageBox>

Password::Password(Admin &a, QMainWindow *parent)
	:admin{ a },password{"Leptop37"},QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

void Password::checkAndShow()
{
	std::string s = this->ui.lineEdit->text().toStdString();
	this->ui.lineEdit->clear();
	if (s != this->password)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString("Incorrect password!"));
		return;
	}
	else
	{
		this->hide();
		this->admin.show();
	}
}

void Password::connectSignalsAndSlots()
{
	this->ui.lineEdit->setEchoMode(QLineEdit::Password);
	QObject::connect(this->ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(checkAndShow()));

	QObject::connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(checkAndShow()));
}