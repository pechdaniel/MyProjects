#include "OOPPracticalex.h"
#include <QtWidgets/QApplication>
#include "MainTeacher.h"
#include "controller.h"
#include "repository.h"
#include "TeacherWindow.h"
#include "student.h"
#include "teacher.h"
#include "studentRepo.h"
#include "teacherRepo.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository<Student>* st=new StudentRepo<Student>{ "Students.txt" };
	Repository<Teacher>* te=new TeacherRepo<Teacher>{ "Teachers.txt" };
	Controller c{ st,te };
	HeadTeacher teacher{ c };
	teacher.show();
	return a.exec();
}
