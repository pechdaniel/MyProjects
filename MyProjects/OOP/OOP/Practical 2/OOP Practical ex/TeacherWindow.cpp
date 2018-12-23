#include "TeacherWindow.h"
#include <string>

using namespace std;

SepareteTeacher::SepareteTeacher(Repository<Student>* r,std::string name,std::vector<int> gr, QWidget *parent)
	:repo{ r }, name{ name }, groups{ gr }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	this->students = this->repo->getByGroups(gr);
	this->populate();
}

void SepareteTeacher::connectSignalsAndSlots()
{
	QObject::connect(ui.GradeButton, SIGNAL(clicked()), this, SLOT(grade()));
}

int SepareteTeacher::getSelectedIndex()
{
	if (ui.StudentList->count() == 0)
		return -1;
	QModelIndexList indexList = this->ui.StudentList->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void SepareteTeacher::populate()
{
	if (ui.StudentList->count() != 0)
		ui.StudentList->clear();
	for (auto m : this->students)
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.StudentList->addItem(listItemWidget);
	}
	if (students.size() > 0)
		ui.StudentList->setCurrentRow(0);
}

void SepareteTeacher::grade()
{
	string g = ui.GradeLine->text().toStdString();
	double gr = stod(g);
	int k = this->getSelectedIndex();
	int id = students[k].getID();
	students[k].setGrade(gr);
	int f = repo->findByID(id);
	repo->setGrade(f, gr);
	this->populate();
}