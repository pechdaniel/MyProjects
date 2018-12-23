#include "Vegetables.h"
#include <QtWidgets/QApplication>
#include "repository.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r{ "All.txt" };
	//Vegetable v1{ "Potato family", "Potato",{ "fruit" } };
	//Vegetable v2{ "Potato family", "Tomato",{ "fruit" } };
	//Vegetable v3{ "Beetroot family", "Spinach",{ "leaves" } };
	//Vegetable v4{ "Marrow family", "Melon",{ "fruit" } };
	//Vegetable v5{ "Onion family", "Onion",{ "stem","root" } };
	//r.add(v1);
	//r.add(v2);
	//r.add(v3);
	//r.add(v4);
	//r.add(v5);
	Vegetables w{ r };
	w.show();
	return a.exec();
}
