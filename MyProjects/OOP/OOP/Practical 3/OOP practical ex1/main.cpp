#include "OOPpracticalex1.h"
#include <QtWidgets/QApplication>
#include "student.h"
#include "teacher.h"
#include "studentRepo.h"
#include "teacherRepo.h"
#include "controller.h"
#include "MainTeacher.h"
#include "SomeTeacher.h"

void testAdd()
{
	StudentRepo<Student> s{};
	Student s1{ 1,"Ni",1,10,"Teacher" };
	Student s2{ 2,"Ion",1,10,"Hiji" };
	Student s3{ 3,"Wai",1,10,"Yoi" };
	Student s4{ 4,"Uite",1,10,"Kiwi" };
	s.add(s1);
	s.add(s2);
	s.add(s3);
	s.add(s4);
	assert(s[0].getGrade() == 10);
	assert(s[1].getName() == "Ion");
	assert(s[3].getTeacher() == "Kiwi");
}
void testDel()
{
	StudentRepo<Student> s{};
	Student s1{ 1,"Ni",1,10,"Teacher" };
	Student s2{ 2,"Ion",1,10,"Hiji" };
	Student s3{ 3,"Wai",1,10,"Yoi" };
	Student s4{ 4,"Uite",1,10,"Kiwi" };
	s.add(s1);
	s.add(s2);
	s.add(s3);
	s.add(s4);
	assert(s.getLenght() == 4);
	s.del(2);
	assert(s[2].getName() == "Uite");
	assert(s.getLenght() == 3);
}
void testSetTeacher()
{
	StudentRepo<Student> s{};
	Student s1{ 1,"Ni",1,10,"Teacher" };
	Student s2{ 2,"Ion",1,10,"Hiji" };
	Student s3{ 3,"Wai",1,10,"Yoi" };
	Student s4{ 4,"Uite",1,10,"Kiwi" };
	s.add(s1);
	s.add(s2);
	s.add(s3);
	s.add(s4);
	s.setTeacher(2, "Ionci");
	assert(s[2].getTeacher() == "Ionci");
}
void testGradeStudent()
{
	StudentRepo<Student> s{};
	Student s1{ 1,"Ni",1,10,"Teacher" };
	Student s2{ 2,"Ion",1,10,"Hiji" };
	Student s3{ 3,"Wai",1,10,"Yoi" };
	Student s4{ 4,"Uite",1,10,"Kiwi" };
	s.add(s1);
	s.add(s2);
	s.add(s3);
	s.add(s4);
	s.gradeStudent(2, 9.5);
	assert(s[2].getGrade() == 9.5);
}

void testAll()
{
	testAdd();
	testDel();
	testSetTeacher();
	testGradeStudent();
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testAll();
	StudentRepo<Student> s{ "Students.txt" };
	TeacherRepo<Teacher> t{ "Teachers.txt" };
	Controller c{ s,t };
	MainTeacher m{ c };
	m.show();
	return a.exec();
}
