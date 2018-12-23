#include "operation.h"

void Operation::push(OperationElement o)
{
	this->operation.push_back(o);
}

OperationElement Operation::pop()
{
	OperationElement e = this->operation[this->operation.size() - 1];
	this->operation.erase(this->operation.begin() + this->operation.size() - 1);
	return e;
}
