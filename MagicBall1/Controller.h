#pragma once
#include "Board.h"
class Controller
{
public:
	Controller(int x, int y);
	~Controller();
	void InitBoard();
	void PrintBoard();
	void DrawBall(int x, int y, BALLTYPE type = 0);
	void UpdateScore(int score);

	static int Size;
	int _x = 9;
	int _y = 9;
	int _mode = EASY;
	Board _board;
};

