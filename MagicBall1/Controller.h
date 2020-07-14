#pragma once
#include "Board.h"
class Controller
{
public:
	Controller(int x, int y);
	~Controller();
	void Play();
	static int Size;
private:
	void _initBoard();
	void _printBoard();
	void _drawBall(int x, int y, BALLTYPE type = 0);
	void _selectBall(int x, int y);
	void _updateScore(int score);
	bool _getCommand();
	
	int _x = 9;
	int _y = 9;
	int _mode = EASY;
	Board _board;
};

