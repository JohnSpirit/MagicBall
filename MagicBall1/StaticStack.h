#pragma once
#include "MDUTD.h"
class StaticStack
{
public:
	StaticStack(int length);
	~StaticStack();

	bool Push(int x,int y);
	bool Push(COORD c);
	COORD Pop();
	COORD operator[](int index)const;
	COORD& operator[](int index);


	int _maxlen = 0;
	int _nowlen = -1;
	COORD* _stackptr = nullptr;
};

