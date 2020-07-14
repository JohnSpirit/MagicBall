#include "StaticStack.h"


StaticStack::StaticStack(int length):_maxlen(length)
{
	this->_stackptr = new StackNode[this->_maxlen];

}

StaticStack::~StaticStack()
{
	delete[] this->_stackptr;
}

bool StaticStack::Push(int x, int y, BALLTYPE bt)
{
	if (this->_nowlen == this->_maxlen - 1)return false;
	else
	{
		this->_nowlen++;
		this->_stackptr[this->_nowlen].cd.X = x;
		this->_stackptr[this->_nowlen].cd.Y = y;
		this->_stackptr[this->_nowlen].bt = bt;
		this->_stackptr[this->_nowlen].dir = LEFT;
		return true;
	}
}

bool StaticStack::Push(Coord c, BALLTYPE bt)
{
	if (this->_nowlen == this->_maxlen - 1)return false;
	else
	{
		this->_nowlen++;
		this->_stackptr[this->_nowlen].cd = c;
		this->_stackptr[this->_nowlen].bt = bt;
		this->_stackptr[this->_nowlen].dir = LEFT;
		return true;
	}
}

Coord StaticStack::Pop()
{
	if (this->_nowlen == -1)
	{
		Coord c(-1,-1);
		return c;
	}
	else
		return this->_stackptr[this->_nowlen--].cd;
}

StackNode StaticStack::operator[](int index) const
{
	if (index == -1 && this->_nowlen > -1)
	{
		return this->_stackptr[this->_nowlen];

	}
	if (index > -1 && index <= this->_nowlen)
	{
		return this->_stackptr[index];
	}

	StackNode s(-1,-1,-1,-1);
	return s;
}

StackNode & StaticStack::operator[](int index)
{
	if (index == -1)
	{
		if (this->_nowlen > -1)return this->_stackptr[this->_nowlen];

	}
	if (index > -1 && index <= this->_nowlen)
	{
		return this->_stackptr[index];
	}
	cerr << "OutOfRangeError!!" << endl;
	exit(EXIT_FAILURE);
}
