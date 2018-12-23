#include "csv.h"
#include <fstream>
#include <string>
#include <sstream>
#include "repoException.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;

void CSV::writeToFile()
{
	std::ofstream file(this->getFile());
	if (!file.is_open())
		throw FileExceptionF("This file can not be opened!");

	for (int i = 0;i < this->getLenght();i++)
		file << this->getAll()[i].stri() << '\n';
	file.close();
}

void CSV::display()
{
	string aux = "\"" + this->getFile() + "\"";
	ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}

//void CSV::readFromFile()
//{
//	ifstream f(this->getFilename());
//	if (!f.is_open())
//		return;
//
//	std::string t, i;
//
//	while (getline(f, i))
//	{
//		std::vector<string> v;
//		std::stringstream line(i);
//		while (getline(line, t, ','))
//			v.push_back(t);
//		string t, g, tr;
//		int y, l;
//		t = v[0];
//		g = v[1];
//		y = stoi(v[2]);
//		l = stoi(v[3]);
//		tr = v[4];
//		Movie m{ t,g,y,l,tr };
//		this->add(m);
//	}
//	f.close();
//}
