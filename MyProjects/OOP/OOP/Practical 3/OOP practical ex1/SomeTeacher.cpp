#include "SomeTeacher.h"
#include <QMessageBox>
#include <string>

using namespace std;

SomeTeacher::SomeTeacher(StudentRepo<Student>& s, std::string name, std::vector<int> gr, QWidget *parent)
	:students{ s }, groups{ gr }, name{ name }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->flt = s.getByGroups(gr);
	this->setWindowTitle(QString::fromStdString(name));

	this->connectSignalsAndSlots();
	this->populate();	
}

void SomeTeacher::populate()
{
	flt = students.getByGroups(groups);
	if (ui.StudentList->count() != 0)
		ui.StudentList->clear();
	for (auto m : this->flt)
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.StudentList->addItem(listItemWidget);
	}
	if (flt.size() > 0)
		ui.StudentList->setCurrentRow(0);
}

void SomeTeacher::connectSignalsAndSlots()
{
	QObject::connect(ui.GradeButton, SIGNAL(clicked()), this, SLOT(grade()));
}

int SomeTeacher::getSelectedIndex()
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

void SomeTeacher::grade()
{
	int k = this->getSelectedIndex();
	int id = flt[k].getID();
	string l = flt[k].getTeacher();
	if (l != name && l!=" " && l!="")
	{
		ui.GradeLine->clear();
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString("You cannot grade a student that was graded by another teacher!"));
		return;
	}
	int it = students.findByID(id);
	string f = ui.GradeLine->text().toStdString();
	double grade = stod(f);
	students.gradeStudent(it, grade);
	students.setTeacher(it, name);
	flt[k].setGrade(grade);
	flt[k].setTeacher(name);
	this->populate();
	ui.GradeLine->clear();
}