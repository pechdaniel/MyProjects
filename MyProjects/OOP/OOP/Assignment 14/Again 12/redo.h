#pragma once
#include "operation.h"

class Redo :public Operation
{
public:
	Redo(Repository r) :Operation(r) {}
	~Redo() {}
	void execute() override;
};