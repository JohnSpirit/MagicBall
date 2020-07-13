#include "StaticStack.h"


StaticStack::StaticStack(int length):_maxlen(length)
{
	this->_stackptr = new COORD[this->_maxlen];

}

StaticStack::~StaticStack()
{
	delete[] this->_stackptr;
}

bool StaticStack::Push(int x, int y)
{
	if (this->_nowlen == this->_maxlen - 1)return false;
	else
	{
		this->_nowlen++;
		this->_stackptr[this->_nowlen].X = x;
		this->_stackptr[this->_nowlen].Y = y;
		return true;
	}
}

bool StaticStack::Push(COORD c)
{
	if (this->_nowlen == this->_maxlen - 1)return false;
	else
	{
		this->_nowlen++;
		this->_stackptr[this->_nowlen] = c;
		return true;
	}
}

COORD StaticStack::Pop()
{
	if (this->_nowlen == -1)
	{
		COORD c{ -1,-1 };
		return c;
	}
	else
		return this->_stackptr[this->_nowlen--];
}

COORD StaticStack::operator[](int index) const
{
	if (index == -1 && this->_nowlen > -1)
	{
		return this->_stackptr[this->_nowlen];

	}
	if (index > -1 && index <= this->_nowlen)
	{
		return this->_stackptr[index];
	}

	COORD c{ -1,-1 };
	return c;
}

COORD & StaticStack::operator[](int index)
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
