#pragma once

constexpr int LEFT = 1;
constexpr int RIGHT = 5;
constexpr int UP = 2;
constexpr int DOWN = 3;
constexpr int COL = 1;
constexpr int ROW = 2;
constexpr int ALL = 0;

constexpr int EASY = 4;
constexpr int NORMAL = 5;
constexpr int HARD = 6;

#define REV(x) (5-x)

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <easyx.h>
#include <ctime>

using namespace std;

template<typename T>
constexpr T random(T x) { return ((T)(x*rand()/(0x7fff+1.0F))); }

typedef signed char int8;
typedef int8 BALLTYPE;
typedef short int16;
typedef signed char loop_control;
typedef signed char DIR;


typedef struct
{
	BALLTYPE bt;
	COORD cd;
}BALL;