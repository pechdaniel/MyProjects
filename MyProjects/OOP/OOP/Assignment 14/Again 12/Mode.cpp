#include "Mode.h"
#include "Admin.h"
#include "User.h"

Mode::Mode(Admin &a,User &u,Repository &r, Repository &l,QWidget *parent)
	:password{ a }, r{ r }, l{ l }, QMainWindow(parent)
{
	this->table = new View(r, l);
	this->setAdmin(a);
	this->setUser(u);
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

void Mode::AdminMode()
{

	this->adm->show();

}

void Mode::UserMode()
{

	this->usr->readFromFile();
	this->usr->show();

}

void Mode::passwordShow()
{
	this->password.readFromFile();
	this->password.show();
}

void Mode::viewAll()
{
	delete this->table;
	this->r.clr();
	this->l.clr();
	this->r.readFromFile();
	this->l.readFromFile();
	this->table = new View(this->r, this->l);
	this->table->show();
}

void Mode::connectSignalsAndSlots()
{
	//QObject::connect(this->ui.AdminButton, SIGNAL(clicked()), this, SLOT(AdminMode()));

	QObject::connect(this->ui.AdminButton, SIGNAL(clicked()), this, SLOT(passwordShow()));

	QObject::connect(this->ui.UserButton, SIGNAL(clicked()), this, SLOT(UserMode()));

	QObject::connect(this->ui.ViewButton, SIGNAL(clicked()), this, SLOT(viewAll()));
}

void Mode::setAdmin(Admin & a)
{
	this->adm = &a;
}

void Mode::setUser(User & u)
{
	this->usr = &u;
}
