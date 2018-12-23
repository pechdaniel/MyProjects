#pragma once
#include <string>
#include <vector>

class Teacher
{
private:
	std::string name;
	std::vector<int> groups;
public:
	Teacher(std::string name,std::vector<int> groups) :name{ name }, groups{ groups } {}
	~Teacher() {}

	bool operator==(Teacher t) { return name == t.getName(); }

	std::string getName() { return name; }
	std::vector<int> getGroups() { return groups; }
	std::string toString();
};