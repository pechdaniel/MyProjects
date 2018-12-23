#include "VegetablesProb.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "vegetable.h"

void testSort()
{
	Repository<Vegetable> r{};
	Vegetable v1{ "Pot","Pota",{ "ok" } };
	Vegetable v2{ "Beet","Pota",{ "ok" } };
	r.Add(v1);
	r.Add(v2);
	r.sort();
	assert(r[0].getFamily() == "Beet");
}

void testFilter()
{
	Repository<Vegetable> r{};
	Vegetable v1{ "Beet","Pota",{ "ok" } };
	Vegetable v2{ "Beet","Nii",{ "ok" } };
	r.Add(v1);
	r.Add(v2);
	vector<Vegetable> v = r.filter("Beet");
	assert(v[0].getName() == "Pota");
	assert(v[1].getName() == "Nii");
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testSort();
	testFilter();
	Repository<Vegetable> r{ "All.txt" };
	
	//Vegetable v{ "fbsaf","fsabf",{"das"} };
	//r.add(v);
	VegetablesProb w{ r };
	w.show();
	return a.exec();
}
