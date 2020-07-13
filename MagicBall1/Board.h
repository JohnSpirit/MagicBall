#pragma once
#include "Matrix.h"
class Board:
	public Matrix<BALLTYPE>
{
public:
	Board();
	Board(const Board& b);
	~Board();

	Board operator=(const Board& b);

	void Init();
	bool Move(int8 x1, int8 y1, int8 x2, int8 y2);
	void AddBalls(bool animate=false);
	bool GameOver();


	int _score = 0;
	int _steps = 0;
	int _emptynum = 81;
	COORD* _emptylist = nullptr;

private:
	bool _getPath();
};

