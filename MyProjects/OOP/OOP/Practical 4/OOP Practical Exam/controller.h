#pragma once
#include "ProgrammerRepo.h"
#include "TaskRepo.h"
#include "task.h"
#include "programmer.h"

class Controller
{
private:
	ProgrammerRepo<Programmer>& progs;
	TaskRepo<Task>& tasks;
public:
	Controller(ProgrammerRepo<Programmer>& p, TaskRepo<Task>& t) :progs{ p }, tasks{ t } {}
	Controller() :progs{ ProgrammerRepo<Programmer>() }, tasks{ TaskRepo<Task>() } {}
	~Controller() {}

	ProgrammerRepo<Programmer>& getProgs() { return progs; }
	TaskRepo<Task>& getTasks() { return tasks; }

	void addTask(Task t) { tasks.add(t); }
	//Deletes an element from the given position from the task repository
	//in: int pos, the position of the element
	//out: the element from position pos was deleted from the task repository
	void delTask(int pos) { tasks.del(pos); }

	void saveTasks() { tasks.writeToFile(); }
	void sortTasks() { tasks.sortMe(); }

	//Updates the programmer id for
	void startTask(int pos, int id);
	void finishTask(int pos);

	Controller& operator=(Controller& c);
};