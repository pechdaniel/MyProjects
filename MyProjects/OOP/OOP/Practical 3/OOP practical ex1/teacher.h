#pragma once
#include <string>
#include <vector>

class Teacher
{
private:
	std::string name;
	std::vector<int> groups;
public:
	Teacher(std::string name, std::vector<int> gr) :name{ name }, groups{ gr } {}
	~Teacher() {}

	std::string getName() { return name; }
	std::vector<int> getGroups() { return groups; }

	void setGroups(std::vector<int> v) { groups = v; }
	void setName(std::string n) { name = n; }

	std::string toString();
	std::string stri();
};