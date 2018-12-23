#pragma once
#include "ui_TeacherWindow.h"
#include <QtWidgets/QMainWindow>
#include "student.h"
#include "repository.h"

class SepareteTeacher : public QMainWindow
{
	Q_OBJECT

public:
	SepareteTeacher(Repository<Student>* r,std::string name,std::vector<int> gr, QWidget *parent = Q_NULLPTR);
	~SepareteTeacher() {}
	void populate();
private:
	Ui::TeacherWindow ui;
	std::vector<Student> students;
	Repository<Student>* repo;
	std::string name;
	std::vector<int> groups;

	void connectSignalsAndSlots();
	int getSelectedIndex();
	private slots:
	void grade();
};