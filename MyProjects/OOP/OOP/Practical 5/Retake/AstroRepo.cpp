#include "AstroRepo.h"
#include <fstream>
#include <sstream>

using namespace std;

void AstroRepo::readFromFile()
{
	std::ifstream file(this->filename);
	std::string t, i;
	if (!file.is_open())
		return;

	while (getline(file, i))
	{
		std::vector<string> v;
		std::stringstream line(i);
		while (getline(line, t, ','))
			v.push_back(t);
		string f, n;
		double p, lo;
		f = v[0];
		n = v[1];
		Astronomer m{ f,n };
		this->elems.push_back(m);
	}
	file.close();
}
