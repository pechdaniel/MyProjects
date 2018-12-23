#pragma once
#include <string>

class Student
{
private:
	int id;
	std::string name;
	int group;
	double grade;
	std::string teacher;
public:
	Student(int id, std::string name, int group) :id{ id }, name{ name }, group{ group }, grade{ 1 }, teacher{ " " } {}
	Student(int id, std::string name, int group,double grade,std::string teacher) :id{ id }, name{ name }, group{ group }, grade{ grade }, teacher{ teacher } {}
	~Student() {}

	int getID() { return id; }
	std::string getName() { return name; }
	int getGroup() { return group; }
	double getGrade() { return grade; }
	std::string getTeacher() { return teacher; }

	void setGrade(double gr) { grade = gr; }
	void setTeacher(std::string name) { teacher = name; }

	std::string toString();
	std::string stri();
};