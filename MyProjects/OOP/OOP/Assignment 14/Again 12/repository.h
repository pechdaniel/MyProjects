#pragma once
#include "movie.h"
#include <vector>

class Repository {
private:
	std::vector<Movie> elems{};
	std::string filename;
	int current;
public:
	Repository() :filename{ "" }, current{ 0 } {}
	Repository(std::string filename) :filename{ filename }, current{ 0 } { this->readFromFile(); }
	~Repository() {}
	std::string toString();
	std::string getFile() { return filename; }
	Movie operator[](int pos) { return elems[pos]; }
	std::vector<Movie> getAll() { return elems; }
	int getLenght() { return this->elems.size(); }
	int getCurrent() { return current; }
	void add(Movie m);
	void del(int pos);
	void update(std::string oTitle, std::string nTitle, std::string genre, int year, int likes, std::string trailer);
	void clr() { elems.clear(); }
	std::vector<Movie> filterRepo(std::string s);
	void setFilename() { filename = ""; }

	int findByTitle(std::string title);
	std::string next();
	void incLikes(int pos) { elems[pos].incLikes(); }
	void setElems(std::vector<Movie> v) { elems = v; }
	void operator=(Repository r);
	void setCurrent(int i) { current = i; }
	void Add(Movie m) { elems.push_back(m); }
	void Del(int pos) { elems.erase(elems.begin() + pos); }

	void writeToFile();
	void readFromFile();
	void displayCSV();
};