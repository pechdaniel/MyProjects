#pragma once
#include <string>

class Student {
private:
	int id;
	std::string name;
	int age;
public:
	Student() :id(), name(""), age() {}
	Student(int _id, std::string _name, int _age) :id{ _id }, name{ _name }, age{ _age } { }
	int getID() { return id; };
	std::string getName() { return name; }
	int getAge() { return age; }
	void setName(std::string name);
	void setAge(int age);
	bool operator==(Student s) { return (s.id == this->id && s.name == this->name && s.age == this->age); }
	virtual std::string overString();
};