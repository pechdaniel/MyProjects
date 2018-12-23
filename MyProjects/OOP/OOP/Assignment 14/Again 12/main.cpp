#include "Again12.h"
#include "Admin.h"
#include "User.h"
#include "Mode.h"
#include <QtWidgets/QApplication>

#include "movie.h"
#include "repository.h"
#include "controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r{ "All.txt" };
	Repository l{ "List.txt" };
	Controller c{ r,l };
	Admin w2{ r };
	User w3{ c };
	Mode w1{ w2,w3,r,l };
	w1.show();
	return a.exec();
}
