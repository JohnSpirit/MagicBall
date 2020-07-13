#pragma once
#include "MDUTD.h"
class StaticStack
{
public:
	StaticStack(int length);
	~StaticStack();

	COORD Push();
	COORD Pop();

	int _maxlen = 0;
	int _nowlen = -1;
	COORD* _stackptr = nullptr;
};

