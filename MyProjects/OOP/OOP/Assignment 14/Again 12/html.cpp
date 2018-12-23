#include "html.h"
#include <fstream>
#include "repoException.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>

using namespace std;

void HTML::setRepo(Repository r)
{
	this->repo = r;
	this->writeToFile();
}

void HTML::writeToFile()
{
	std::ofstream file(this->filename);
	if (!file.is_open())
		throw FileExceptionF("Error opening file for writing!");
	file << "<!DOCTYPE html> \n <html> \n \t<head> \n \t\t <title>MovieList</title> \n";
	file << "\t</head> \n \t<body> \n \t\t<table border=\"1\"> \n \t\t<tr>\n";
	file << "\t\t\t<td>Title</td> \n \t\t\t<td>Genre</td> \n \t\t\t<td>Year</td> \n \t\t\t <td>Likes</td>\n";
	file << "\t\t\t<td>Link to trailer</td> \n \t\t </tr>\n";
	for (auto dog : this->repo.getAll())
	{
		file << "\t\t<tr>\n";
		file << "\t\t\t<td>" << dog.getTitle() << "</td>\n";
		file << "\t\t\t<td>" << dog.getGenre() << "</td>\n";
		file << "\t\t\t<td>" << dog.getYear() << "</td>\n";
		file << "\t\t\t<td>" << dog.getLikes() << "</td>\n";
		file << "\t\t\t<td><a href=" << dog.getTrailer() << ">Link</td>\n";
		file << "\t\t</tr>\n";
	}
	file << "\t\t</table>\n";
	file << "\t</body>\n";
	file << "</html>\n";
	file.close();
}

void HTML::displayHTML()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", "file:///C:/Users/daniel/Documents/Visual%20Studio%202017/Projects/Again%2012/Again%2012/HTMLfile.html", NULL, SW_SHOWMAXIMIZED);
}
