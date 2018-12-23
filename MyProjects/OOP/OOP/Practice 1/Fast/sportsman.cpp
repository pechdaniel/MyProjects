#include "sportsman.h"
#include <sstream>

using namespace std;

std::string Sportsman::overString()
{
	stringstream lol;
	lol << "Aiesta are numele " << this->getName() << " cu ID " << this->getID() << " si varsta de " << this->getAge() << " si mai face si " << this->getSport();
	return lol.str();
}
