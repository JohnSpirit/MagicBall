#include "StaticStack.h"


StaticStack::StaticStack(int length):_maxlen(length)
{
	this->_stackptr = new COORD[this->_maxlen];

}

StaticStack::~StaticStack()
{
	delete[] this->_stackptr;
}

COORD StaticStack::Push()
{

	return COORD();
}

COORD StaticStack::Pop()
{
	return COORD();
}
