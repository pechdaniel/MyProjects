#pragma once
#include "studentRepo.h"
#include "teacherRepo.h"

class Controller
{
private:
	StudentRepo<Student>& students;
	TeacherRepo<Teacher>& teachers;
public:
	Controller(StudentRepo<Student>& st, TeacherRepo<Teacher>& te) :students{ st }, teachers{ te } {}
	~Controller() {}

	StudentRepo<Student>& getStudents() { return students; }
	TeacherRepo<Teacher>& getTeachers() { return teachers; }
	std::vector<std::string> getTeachersNames();

	void addStudent(Student s) { students.add(s); }
	void delStudent(int pos) { students.del(pos); }
	std::vector<int> getTeacherGroups(std::string name);

	void saveStudents() { students.writeToFile(); }
	void sortMe() { this->students.sortMe(); }

	int getValidID();
};
