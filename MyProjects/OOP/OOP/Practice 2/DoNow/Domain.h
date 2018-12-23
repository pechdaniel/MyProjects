#pragma once
#include <string>

class Pilot {
private:
	std::string name;
	int age;
	int flights;
	int id;
public:
	Pilot();
	Pilot(const std::string name, const int age, const int flights, const int id);
	std::string getName() { return name; }
	int getAge() { return age; }
	int getFlights() { return flights; }
	int getID() { return id; }
	bool operator==(Pilot p1) { return (p1.name == this->name&&p1.age == this->age&&p1.flights == this->flights&&p1.id == this->id); }
	void setName(std::string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setFlights(int flights) { this->flights = flights; }
};