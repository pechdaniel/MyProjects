#include "ProgrammerWindow.h"
#include <string>
#include <QMessageBox>

using namespace std;

ProgrammerWindow::ProgrammerWindow(Controller& c, Programmer p, std::vector<ProgrammerWindow*> v, QWidget *parent)
	:controller{ c }, prog{ p }, allWindows{ v }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(p.getName()));
	this->connectSignalsAndSlots();
	this->populate();
}

ProgrammerWindow::ProgrammerWindow(Controller& c, Programmer p, QWidget *parent)
	:controller{ c }, prog{ p }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(p.getName()));
	this->connectSignalsAndSlots();
	this->populate();
}

ProgrammerWindow::ProgrammerWindow(QWidget *parent)
	:controller{Controller()}, prog{ }, allWindows{ }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
}

ProgrammerWindow::~ProgrammerWindow()
{
	controller.saveTasks();
}

void ProgrammerWindow::connectSignalsAndSlots()
{
	QObject::connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(ui.DeleteButton, SIGNAL(clicked()), this, SLOT(del()));
	QObject::connect(ui.StartButton, SIGNAL(clicked()), this, SLOT(start()));
	QObject::connect(ui.DoneButton, SIGNAL(clicked()), this, SLOT(done()));
	//QObject::connect(ui.TaskList, SIGNAL(itemSelectionChanged()), SLOT(checkDel()));
}

int ProgrammerWindow::getSelectedIndex()
{
	if (ui.TaskList->count() == 0)
		return -1;
	QModelIndexList indexList = this->ui.TaskList->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void ProgrammerWindow::populate()
{
	this->controller.sortTasks();

	if (ui.TaskList->count() != 0)
		ui.TaskList->clear();
	for (auto m : this->controller.getTasks().getAll())
	{
		if (m.getID() == -1)
		{
			QString listItem = QString::fromStdString(m.toString());
			QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
			this->ui.TaskList->addItem(listItemWidget);
		}
		else {
			QString listItem = QString::fromStdString(m.toString1());
			QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
			this->ui.TaskList->addItem(listItemWidget);
		}
	}
	if (this->controller.getTasks().getLenght() > 0)
		ui.TaskList->setCurrentRow(0);
	//this->modifyAll();
}

void ProgrammerWindow::showIt()
{
	this->setWindowTitle(QString::fromStdString(prog.getName()));
	this->populate();
	this->show();
}

void ProgrammerWindow::modifyAll()
{
	for (auto i : allWindows)
		i->populate();
}

void ProgrammerWindow::add()
{
	string s = ui.TaskLine->text().toStdString();
	ui.TaskLine->clear();
	Task t{ s };
	this->controller.addTask(t);
	this->populate();
	controller.saveTasks();
}

void ProgrammerWindow::start()
{
	try {
		int k = this->getSelectedIndex();
		int n = prog.getID();
		string na = prog.getName();
		controller.startTask(k, n, na);
		this->populate();
		controller.saveTasks();
	}
	catch (exception& e)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString(e.what()));
	}
}

void ProgrammerWindow::done()
{
	try {
		int k = this->getSelectedIndex();
		if (controller.getTasks()[k].getID() != prog.getID())
		{
			throw Exception{ "Task status is not 'in progress' or you are not the one who started the task!" };
		}
		controller.finishTask(k);
		this->populate();
		controller.saveTasks();
	}
	catch (exception& e)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString(e.what()));
	}
}

void ProgrammerWindow::del()
{
	try {
		int k = this->getSelectedIndex();
		if (controller.getTasks()[k].getIntStat() != 0 || controller.getTasks()[k].getID() != prog.getID())
			throw Exception{ "You cannot delete this item!" };
		controller.delTask(k);
		this->populate();
		controller.saveTasks();
	}
	catch (exception& e)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString(e.what()));
	}
}

void ProgrammerWindow::checkDel()
{
	int k = this->getSelectedIndex();
	if (controller.getTasks()[k].getIntStat() == 0 && controller.getTasks()[k].getID() == prog.getID())
		ui.DeleteButton->setEnabled(true);
	else
		ui.DeleteButton->setDisabled(true);
}
