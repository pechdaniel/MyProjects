#include "controller.h"

void Controller::startTask(int pos, int id)
{
	tasks.setThisProgress(pos);
	tasks.setThisID(pos, id);
}

void Controller::finishTask(int pos)
{
	tasks.setThisClosed(pos);
}

Controller & Controller::operator=(Controller & c)
{
	this->progs = c.progs;
	this->tasks = c.tasks;
	return *this;
}