#include "OOPotherpractical1.h"
#include <QtWidgets/QApplication>
#include "programmer.h"
#include "task.h"
#include "ProgrammerRepo.h"
#include "TaskRepo.h"
#include "controller.h"
#include "ProgrammerWindow.h"
#include <vector>
#include <assert.h>

using namespace std;

void testDelRepo()
{
	Programmer p1{ 1,"Eu" }, p2{ 2,"Celalalt" };
	ProgrammerRepo<Programmer> p{};
	p.add(p1);
	p.add(p2);
	assert(p.getLenght() == 2);
	Task t1{ "Facem asa" }, t2{ "Merge bine" }, t3{ "Uite ca face" };
	TaskRepo<Task> t{};
	t.add(t1);
	t.add(t2);
	t.add(t3);
	assert(t.getLenght() == 3);
	t.del(2);
	assert(t.getLenght() == 2);
	assert(t[t.getLenght() - 1].getDescr() == "Merge bine");
}

void testDelContro()
{
	Programmer p1{ 1,"Eu" }, p2{ 2,"Celalalt" };
	ProgrammerRepo<Programmer> p{};
	p.add(p1);
	p.add(p2);
	assert(p.getLenght() == 2);
	Task t1{ "Facem asa" }, t2{ "Merge bine" }, t3{ "Uite ca face" };
	TaskRepo<Task> t{};
	t.add(t1);
	t.add(t2);
	t.add(t3);
	assert(t.getLenght() == 3);
	Controller co{ p,t };
	co.delTask(2);
	assert(t.getLenght() == 2);
	assert(t[t.getLenght() - 1].getDescr() == "Merge bine");
}

void testUpdateStatusInProgressRepo()
{
	Programmer p1{ 1,"Eu" }, p2{ 2,"Celalalt" };
	ProgrammerRepo<Programmer> p{};
	p.add(p1);
	p.add(p2);
	assert(p.getLenght() == 2);
	Task t1{ "Facem asa" }, t2{ "Merge bine" }, t3{ "Uite ca face" };
	TaskRepo<Task> t{};
	t.add(t1);
	t.add(t2);
	t.add(t3);
	assert(t.getLenght() == 3);
	t.updateStatusProgress(1, p1.getID());
	assert(t[1].getID() == p1.getID());
	assert(t[1].getStat() == "in progress");
}

void testUpdateStatusInProgressContro()
{
	Programmer p1{ 1,"Eu" }, p2{ 2,"Celalalt" };
	ProgrammerRepo<Programmer> p{};
	p.add(p1);
	p.add(p2);
	assert(p.getLenght() == 2);
	Task t1{ "Facem asa" }, t2{ "Merge bine" }, t3{ "Uite ca face" };
	TaskRepo<Task> t{};
	t.add(t1);
	t.add(t2);
	t.add(t3);
	assert(t.getLenght() == 3);
	Controller co{ p,t };
	co.startTask(1, p1.getID(),p1.getName());
	assert(t[1].getID() == p1.getID());
	assert(t[1].getStat() == "in progress");
}

void testUpdateStatusClosedRepo()
{
	Programmer p1{ 1,"Eu" }, p2{ 2,"Celalalt" };
	ProgrammerRepo<Programmer> p{};
	p.add(p1);
	p.add(p2);
	assert(p.getLenght() == 2);
	Task t1{ "Facem asa" }, t2{ "Merge bine" }, t3{ "Uite ca face" };
	TaskRepo<Task> t{};
	t.add(t1);
	t.add(t2);
	t.add(t3);
	assert(t.getLenght() == 3);
	t.updateStatusProgress(1, p1.getID());
	t.setThisClosed(1);
	assert(t[1].getID() == p1.getID());
	assert(t[1].getStat() == "closed");
}

void testUpdateStatusClosedContro()
{
	Programmer p1{ 1,"Eu" }, p2{ 2,"Celalalt" };
	ProgrammerRepo<Programmer> p{};
	p.add(p1);
	p.add(p2);
	assert(p.getLenght() == 2);
	Task t1{ "Facem asa" }, t2{ "Merge bine" }, t3{ "Uite ca face" };
	TaskRepo<Task> t{};
	t.add(t1);
	t.add(t2);
	t.add(t3);
	assert(t.getLenght() == 3);
	Controller co{ p,t };
	co.startTask(1, p1.getID(),p1.getName());
	co.finishTask(1);
	assert(t[1].getID() == p1.getID());
	assert(t[1].getStat() == "closed");
}

void testAll()
{
	testDelRepo();
	testDelContro();
	testUpdateStatusInProgressRepo();
	testUpdateStatusInProgressContro();
	testUpdateStatusClosedRepo();
	testUpdateStatusClosedContro();
}

class Here
{
private:
	vector<ProgrammerWindow*> hm;
public:
	Here(vector<ProgrammerWindow*> h) :hm{ h } {}
	~Here() {
		for (auto i : hm)
			delete i;
	}
	void show() {
		for (auto i : hm)
			i->show();
	}
};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testAll();
	ProgrammerRepo<Programmer> p{ "Programmers.txt" };
	TaskRepo<Task> t{ "Tasks.txt" };
	Controller c{ p,t };
	std::vector<ProgrammerWindow*> v;
	vector<Programmer> names;
	for (auto i : p.getAll())
	{
		names.push_back(i);
		ProgrammerWindow* pr = new ProgrammerWindow(c,i);
		v.push_back(pr);
	}
	for (auto j : names)
	{
		for (int i = 0;i < names.size();i++)
		{
			v[i]->setAll(v);
		}
	}
	Here h{ v };
	h.show();
	return a.exec();
}
