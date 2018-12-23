#pragma once
#include <string>

class Task
{
private:
	std::string description;
	int stat;
	std::string status;
	int programmerid;
public:
	Task() :stat{}, status{ "" }, programmerid{}, description{ "" } {}
	Task(std::string descr) :stat{ -1 }, status{ "open" }, programmerid{}, description{ descr } {}
	Task(std::string descr, int s, int id) :stat{ s }, description{ descr }, programmerid{ id }
	{
		if (s == -1)
			status = "open";
		if (s == 0)
			status = "in progress";
		if (s == 1)
			status = "closed";
	}
	~Task() {}

	int getIntStat() { return stat; }
	std::string getStat() { return status; }
	std::string getDescr() { return description; }
	int getID() { return programmerid; }

	void setProgress() { stat = 0; status = "in progress"; }
	void setClosed() { stat = 1;status = "closed"; }
	void setID(int id) { programmerid = id; }

	std::string toString();
	std::string stri();
};