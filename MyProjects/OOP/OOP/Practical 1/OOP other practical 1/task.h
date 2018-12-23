#pragma once
#include <string>

class Task
{
private:
	std::string description;
	int stat;
	std::string status;
	int programmerid;
	std::string progName;
public:
	Task() :stat{}, status{ "" }, programmerid{ -1 }, description{ "" }, progName{ " " } {}
	Task(std::string descr) :stat{ -1 }, status{ "open" }, programmerid{ -1 }, description{ descr }, progName{ " " } {}
	Task(std::string descr, int s, int id, std::string pn) :stat{ s }, description{ descr }, programmerid{ id }, progName{ pn }
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
	std::string getProgName() { return progName; }

	void setProgress() { stat = 0; status = "in progress"; }
	void setClosed() { stat = 1;status = "closed"; }
	void setID(int id) { programmerid = id; }
	void setProgName(std::string n) { progName = n; }

	std::string toString();
	std::string toString1();
	std::string stri();
};