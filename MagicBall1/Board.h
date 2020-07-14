#pragma once
#include "Matrix.h"
#include "StaticStack.h"
class Board:
	public Matrix<BALLTYPE>
{
public:
	Board();
	Board(int x,int y);
	Board(const Matrix<BALLTYPE>& b);
	Board(const Board& b);
	~Board();

	Board& operator=(const Board& b);

	void Init();
	bool Move(int8 x1, int8 y1, int8 x2, int8 y2);
	bool Move(const Coord& from, const Coord& to);
	bool AddBalls(bool animate=false);
	bool GameOver();
	bool Check();

	int _score = 0;
	int _steps = 0;
	int _emptynum = 0;
	Coord* _emptylist = nullptr;
	StaticStack _pathstack;
	StackNode _balls_to_remove;
private:
	bool _getPath(int8 x1, int8 y1, int8 x2, int8 y2);
	BALLTYPE _sniff(Coord c,DIR dir);
	Coord _sniff_coord(Coord c, DIR dir);
	int _min_balls = 5;
};

