#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OtherWindow.h"
#include "teacher.h"
#include "student.h"
#include "studentRepo.h"

class SomeTeacher : public QMainWindow
{
	Q_OBJECT

public:
	SomeTeacher(StudentRepo<Student>& s,std::string name, std::vector<int> gr, QWidget *parent = Q_NULLPTR);
	~SomeTeacher() {}
	void populate();
private:
	Ui::OtherWindow ui;
	StudentRepo<Student>& students;
	std::vector<Student> flt;
	std::vector<int> groups;
	std::string name;

	void connectSignalsAndSlots();
	int getSelectedIndex();

	private slots:
	void grade();
};
