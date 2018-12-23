#include "MainTeacher.h"
#include "TeacherWindow.h"
#include <string>

using namespace std;

HeadTeacher::HeadTeacher(Controller& c, QWidget *parent)
	:controller{ c }, currentID{ 20 }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	this->showAll();
	this->populate();
	this->modifyAll();
}

void HeadTeacher::connectSignalsAndSlots()
{
	QObject::connect(ui.AddButton, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(ui.DeleteButton, SIGNAL(clicked()), this, SLOT(del()));
}

int HeadTeacher::getSelectedIndex()
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

void HeadTeacher::populate()
{
	if (ui.listWidget->count() != 0)
		ui.listWidget->clear();
	for (auto m : this->controller.getStudents()->getAll())
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.listWidget->addItem(listItemWidget);
	}
	if (this->controller.getStudents()->getLenght() > 0)
		ui.listWidget->setCurrentRow(0);
}

void HeadTeacher::modifyAll()
{
	for (auto i : this->all)
		i->populate();
}

void HeadTeacher::showAll()
{
	for (auto i : controller.getTeachers()->getAll())
	{
		SepareteTeacher* t = new SepareteTeacher(controller.getStudents(), i.getName(), i.getGroups());
		all.push_back(t);
		t->show();
	}
}

void HeadTeacher::add()
{
	std::string name = ui.NameLine->text().toStdString();
	std::string gr = ui.GroupLine->text().toStdString();
	int group = stoi(gr);
	Student s{currentID, name,group };
	currentID++;
	this->controller.addStudent(s);
	this->populate();
	this->modifyAll();
}

void HeadTeacher::del()
{
	int k = this->getSelectedIndex();
	this->controller.delStudent(k);
	this->populate();
	this->modifyAll();
}
