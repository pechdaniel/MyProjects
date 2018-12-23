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
	Student(int id, std::string name, int group) :id{ id }, name{ name }, group{ group }, grade{ 1 }, teacher { "" } {}
	Student(int id, std::string name, int group, double grade,std::string teacher) :id{ id }, name{ name }, group{ group }, grade{ grade }, teacher { teacher } {}
	~Student() {}

	bool operator==(Student t) { return id == t.getID(); }

	int getID() { return id; }
	std::string getName() { return name; }
	int getGroup() { return group; }
	double getGrade() { return grade; }
	void setGrade(double gr) { grade = gr; }
	std::string getTeacher() { return teacher; }
	std::string toString();
	std::string stri();
};