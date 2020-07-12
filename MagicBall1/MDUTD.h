#pragma once

#define LEFT 1
#define RIGHT 4
#define UP 2
#define DOWN 3
#define REV(x) (5-x)

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <easyx.h>

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