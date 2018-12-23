#include "MainTeacher.h"
#include <QMessageBox>
#include <string>
#include <QIcon>

using namespace std;

MainTeacher::MainTeacher(Controller& c,QWidget *parent)
	:controller{ c }, QMainWindow(parent)
{
	ui.setupUi(this);

	this->connectSignalsAndSlots();
	this->populate();
	this->showAll();
}

MainTeacher::~MainTeacher()
{
	this->controller.saveStudents();
	for (auto i : allWindows)
		delete i;
}

void MainTeacher::populate()
{
	if (ui.listWidget->count() != 0)
		ui.listWidget->clear();
	for (auto m : this->controller.getStudents().getAll())
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.listWidget->addItem(listItemWidget);
	}
	if (this->controller.getStudents().getLenght() > 0)
		ui.listWidget->setCurrentRow(0);
	this->modifyAll();
}

void MainTeacher::connectSignalsAndSlots()
{
	QObject::connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(ui.DeleteButton, SIGNAL(clicked()), this, SLOT(del()));
}

void MainTeacher::modifyAll()
{
	for (auto i : allWindows)
	{
		i->populate();
	}
}

void MainTeacher::showAll()
{
	vector<string> names = controller.getTeachersNames();

	for (auto i : names)
	{
		SomeTeacher* t = new SomeTeacher(controller.getStudents(), i, controller.getTeacherGroups(i));
		this->allWindows.push_back(t);
		t->show();
	}
}

int MainTeacher::getSelectedIndex()
{
	if (ui.listWidget->count() == 0)
		return -1;
	QModelIndexList indexList = this->ui.listWidget->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void MainTeacher::add()
{
	std::string name = ui.NameLine->text().toStdString();
	std::string gr = ui.GroupLine->text().toStdString();
	int group = stoi(gr);
	int validID = controller.getValidID();
	Student s{ validID, name,group };
	this->controller.addStudent(s);
	controller.sortMe();
	this->modifyAll();
	this->populate();
	ui.GroupLine->clear();
	ui.NameLine->clear();
}

void MainTeacher::del()
{
	QMessageBox msgBox;
	if (msgBox.question(this, "Delete", "Do you want to delete the elements?", QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel)
		return;

	int k = this->getSelectedIndex();
	this->controller.delStudent(k);
	this->modifyAll();
	this->populate();
}
