#include "StaticStack.h"


StaticStack::StaticStack(int length):_maxlen(length)
{
	this->_stackptr = new StackNode[this->_maxlen];
}

StaticStack::~StaticStack()
{
	delete[] this->_stackptr;
}

bool StaticStack::Push(int x, int y, BALLTYPE bt, DIR dir)
{
	if (this->_nowlen == this->_maxlen - 1)return false;
	else
	{
		this->_nowlen++;
		this->_stackptr[this->_nowlen].cd.X = x;
		this->_stackptr[this->_nowlen].cd.Y = y;
		this->_stackptr[this->_nowlen].bt = bt;
		this->_stackptr[this->_nowlen].dir = dir;
		return true;
	}
}

bool StaticStack::Push(Coord c, BALLTYPE bt, DIR dir)
{
	return Push(c.X, c.Y, bt, dir);
}

Coord StaticStack::Pop()
{
	return this->_nowlen == -1 ? Coord(-1, -1) : this->_stackptr[this->_nowlen--].cd;
}

StackNode StaticStack::operator[](int index) const
{
	if (index <= -1 && this->_nowlen + index >= -1)return this->_stackptr[this->_nowlen + index + 1];
	if (index > -1 && index <= this->_nowlen)return this->_stackptr[index];
	return StackNode(-1,-1,-1,-1);
}

StackNode & StaticStack::operator[](int index)
{
	if (index <= -1 && this->_nowlen + index >= -1)return this->_stackptr[this->_nowlen + index + 1];
	if (index > -1 && index <= this->_nowlen)return this->_stackptr[index];
	cerr << "operator[]OutOfRangeError!!" << endl;
	//exit(EXIT_FAILURE);
	system("pause");
	return (*this)[0];
}

bool StaticStack::Has(const Coord & s)
{
	for (loop_control i = 0; i <= this->_nowlen; i++)
		if (this->_stackptr[i].cd == s)return true;
	return false;
}

void StaticStack::Reset()
{
	_nowlen = -1;
}

ostream & operator<<(ostream & o, const StaticStack & s)
{
	cout << endl;
	for (loop_control i = s._nowlen; i >= 0; i--)
	{
		o << "Layer= " << int(i) << "\tCoord: X= " << int(s[i].cd.X) << "\tY= " << int(s[i].cd.Y) << "\tbt= " << int(s[i].bt) << "\tdir= " << int(s[i].dir) << endl;
	}
	return o;
}
