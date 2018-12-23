#include "gamer.h"
#include <sstream>

using namespace std;

std::string Gamer::overString()
{
	stringstream ioi;
	ioi << "Aiesta are numele " << this->getName() << " cu ID " << this->getID() << " si varsta de " << this->getAge() << " si se joaca si " << this->getGame();
	return ioi.str();
}
