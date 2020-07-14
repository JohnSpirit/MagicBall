#pragma once
#include "MDUTD.h"
class StaticStack
{
public:
	StaticStack(int length);
	~StaticStack();

	bool Push(int x,int y, BALLTYPE bt);
	bool Push(Coord c, BALLTYPE bt);
	Coord Pop();
	StackNode operator[](int index)const;
	StackNode& operator[](int index);
	bool Has(const Coord& s);
	void Reset();

	int _maxlen = 0;
	int _nowlen = -1;
	StackNode* _stackptr = nullptr;
};

