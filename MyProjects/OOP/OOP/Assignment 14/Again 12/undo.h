#pragma once
#include "operation.h"

class Undo :public Operation
{
public:
	Undo(Repository r) :Operation{r} {}
	~Undo() {}
	void execute() override;
};