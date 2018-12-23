#include "repository.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include "repoException.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;

std::string Repository::toString()
{
	std::stringstream buff;
	for (int i = 0;i < this->elems.size();i++)
	{
		buff << this->elems[i].toString() << '\n' << '\n';
	}
	return buff.str();
}

void Repository::add(Movie m)
{
	this->elems.push_back(m);
	this->writeToFile();
}

void Repository::del(int pos)
{
	if (pos < 0 || pos >= this->getLenght())
		return;
	this->elems.erase(this->elems.begin() + pos);
	this->writeToFile();
}

void Repository::update(std::string oTitle, std::string nTitle, std::string genre, int year, int likes, std::string trailer)
{
	int k = this->findByTitle(oTitle);
	Movie m = this->elems[k];
	m.setTitle(nTitle);
	m.setGenre(genre);
	m.setYear(year);
	m.setLikes(likes);
	m.setTrailer(trailer);
	this->elems[k] = m;
	this->writeToFile();
}

std::vector<Movie> Repository::filterRepo(std::string s)
{
	vector<Movie> r{};
	for (auto i : this->elems)
	{
		if (i.getGenre().find(s) != std::string::npos || i.getTitle().find(s) != std::string::npos || std::to_string(i.getYear()).find(s) != std::string::npos || std::to_string(i.getLikes()).find(s) != std::string::npos)
			r.push_back(i);
	}
	return r;
}



int Repository::findByTitle(std::string title)
{
	for (int i = 0;i < this->elems.size();i++)
	{
		if (this->elems[i].getTitle() == title)
			return i;
	}
	return -1;
}

std::string Repository::next()
{
	if (this->current == this->getLenght() || this->current == -1)
		this->current = 0;
	this->elems[current].watch();
	this->current++;
	return this->elems[current - 1].toString();
}

void Repository::operator=(Repository r)
{
	for (int i = this->elems.size() - 1;i >= 0;i--)
		this->del(i);
	for (int i = 0;i < r.getLenght();i++)
		this->add(r[i]);
}

void Repository::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		throw FileExceptionF("This file can not be opened!");

	for (int i = 0;i < this->getLenght();i++)
		file << this->elems[i].stri() << '\n';
	file.close();
}

void Repository::readFromFile()
{
	std::ifstream file(this->filename);
	std::string t, i;
	if (!file.is_open())
		throw FileExceptionF("This file can not be opened!");
		//return;

	while (getline(file, i))
	{
		std::vector<string> v;
		std::stringstream line(i);
		while (getline(line, t, ','))
			v.push_back(t);
		string t, g, tr;
		int y, l;
		t = v[0];
		g = v[1];
		y = stoi(v[2]);
		l = stoi(v[3]);
		tr = v[4];
		Movie m{ t,g,y,l,tr };
		this->elems.push_back(m);
	}
	file.close();
}

void Repository::displayCSV()
{
	string aux = "\"" + this->getFile() + "\"";
	ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
