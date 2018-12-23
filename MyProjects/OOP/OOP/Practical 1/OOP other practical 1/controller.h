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
	Controller() :progs{ProgrammerRepo<Programmer>()}, tasks{ TaskRepo<Task> ()} {}
	~Controller() {}

	ProgrammerRepo<Programmer>& getProgs() { return progs; }
	TaskRepo<Task>& getTasks() { return tasks; }

	void addTask(Task t) { tasks.add(t); }
	//Deletes an element from position 'pos'
	//in: int pos, the position
	//out: the element on position pos was deleted
	void delTask(int pos) { tasks.del(pos); }

	void saveTasks() { tasks.writeToFile(); }
	void sortTasks() { tasks.sortMe(); }

	//Sets the status of an element from the position 'pos' to 'closed'
	//in: int pos, the position of the element
	//out: the status of an element from the position 'pos' has been set to 'closed'
	void startTask(int pos, int id,std::string n);
	//Sets the status of an element from the position 'pos' to 'in progress' and the programmerID of the task to be the 'id'
	//in: int pos, int id, the position of the element and the new id
	//out: the status of an element from the position 'pos' has been set to 'in progress' and the programmerID is 'id'
	void finishTask(int pos);

	Controller& operator=(Controller& c);
};