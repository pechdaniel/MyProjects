#include "domain.h"
#include <iostream>
using namespace std;

Concert::Concert() :band(""), likes() {}

Concert::Concert(const string band, const int likes)
{
	this->band = band;
	this->likes = likes;
}