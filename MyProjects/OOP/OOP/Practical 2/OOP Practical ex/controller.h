#pragma once
#include "repository.h"
#include "student.h"
#include "teacher.h"

class Controller
{
private:
	Repository<Student>* students;
	Repository<Teacher>* teachers;
public:
	Controller(Repository<Student>* s, Repository<Teacher>* t) :students{ s }, teachers{ t } {}
	Controller() :students{}, teachers{} {}
	~Controller() {}

	Repository<Student>* getStudents() { return students; }
	Repository<Teacher>* getTeachers() { return teachers; }

	void addStudent(Student s);
	int findByID(int id);
	void delStudent(int pos);
};