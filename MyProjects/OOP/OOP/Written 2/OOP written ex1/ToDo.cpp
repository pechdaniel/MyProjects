#include "ToDo.h"

std::ostream & operator<<(std::ostream & o, Activity & a)
{
	o << a.what << " " << a.time;
	return o;
}
