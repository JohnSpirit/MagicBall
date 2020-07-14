#pragma once

constexpr int LEFT = 1;
constexpr int RIGHT = 4;
constexpr int UP = 2;
constexpr int DOWN = 3;

constexpr int LEFTUP = 5;
constexpr int RIGHTUP = 6;

constexpr int COL = 1;
constexpr int ROW = 2;
constexpr int ALL = 0;

constexpr int EASY = 4;
constexpr int NORMAL = 5;
constexpr int HARD = 6;

constexpr int REV(int x) { return 5 - x; }


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <easyx.h>
#include <ctime>
#include <Windows.h>

using namespace std;

template<typename T>
constexpr T random(T x) { return ((T)(x*rand() / (0x7fff + 1.0F))); }

typedef signed char int8;
typedef int8 BALLTYPE;
typedef short int16;
typedef signed char loop_control;
typedef signed char DIR;


class Coord
{
public:
	Coord(int8 x, int8 y) :X(x), Y(y) {};
	Coord() {};
	int8 X=-1;
	int8 Y=-1;
	bool operator==(const Coord& s) { return (this->X == s.X) && (this->Y == s.Y); }
	DIR adj(const Coord& s)
	{
		if (s.X == this->X)
		{
			if (s.Y == this->Y + 1)return UP;
			else if (s.Y == this->Y - 1)return DOWN;
		}
		else if (s.Y == this->Y)
		{
			if (s.X == this->X + 1)return RIGHT;
			else if (s.X == this->X - 1)return LEFT;
		}
		return 0;
	}
};


class StackNode
{
public:
	StackNode(int8 x1, int8 y1, BALLTYPE b, DIR d) :cd(x1, y1), bt(b), dir(d) {};
	StackNode():cd(-1,-1) {};
	Coord cd;
	BALLTYPE bt=-1;
	DIR dir=-1;
};


