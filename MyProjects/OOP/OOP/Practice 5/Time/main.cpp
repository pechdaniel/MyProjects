#include "Time.h"
#include <QtWidgets/QApplication>
#include "domain.h"
#include "repository.h"
#include <assert.h>

using namespace std;

void testSort()
{
	Repository<Task> r{};
	Task t1{ "Ok",1,3 }, t2{ "Vasilica",1,2 }, t3{ "Uite",1,1 };
	r.add(t1);
	r.add(t2);
	r.add(t3);
	r.sort();
	assert(r[0].getDescription() == "Uite");
	assert(r[1].getDescription() == "Vasilica");
	assert(r[2].getDescription() == "Ok");
}

void testCalculateDuration()
{
	Repository<Task> r{};
	Task t1{ "Ok",1,1 }, t2{ "Vasilica",1,1 }, t3{ "Uite",1,1 };
	r.add(t1);
	r.add(t2);
	r.add(t3);
	assert(r.calculateDuration(1) == 3);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testSort();
	testCalculateDuration();
	Repository<Task> r{ "All.txt" };
	Time w{ r };
	w.show();
	return a.exec();
}
