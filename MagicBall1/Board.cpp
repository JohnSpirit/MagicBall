#include "Board.h"


Board::Board():Matrix<BALLTYPE>()
{
}

Board::Board(const Board & b):Matrix<BALLTYPE>(b),_score(b._score),_steps(b._steps)
{

}

Board::~Board()
{
}

Board Board::operator=(const Board & b)
{
	return Board();
}

void Board::Init()
{
}

bool Board::Move(int8 x1, int8 y1, int8 x2, int8 y2)
{
	return false;
}

void Board::AddBalls(bool animate)
{
}

bool Board::GameOver()
{
	return false;
}

bool Board::_getPath()
{
	return false;
}
