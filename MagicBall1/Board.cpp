#include "Board.h"


Board::Board() :Matrix<BALLTYPE>()
{

}

Board::Board(int x, int y) : Matrix<BALLTYPE>(x, y), _emptynum(x*y)
{
	COORD* ptr = nullptr;
	loop_control i, j;
	ptr = this->_emptylist = new COORD[this->_emptynum];
	for (i = 0; i < this->_m; i++)
		for (j = 0; j < this->_n; j++)
		{
			_matptr[i][j] = 0;
			ptr->X = i; ptr->Y = j;
			ptr++;
		}
}

Board::Board(const Matrix<BALLTYPE>& b)
{
}

Board::Board(const Board & b) : Matrix<BALLTYPE>(b), _score(b._score), _steps(b._steps), _emptynum(b._emptynum)
{
	for (loop_control i = 0; i < this->_emptynum; i++)
		this->_emptylist[i] = b._emptylist[i];
}

Board::~Board()
{
	delete this->_emptylist;
}

Board& Board::operator=(const Board & b)
{
	loop_control i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			this->_matptr[i][j] = b._matptr[i][j];
	this->_emptynum = b._emptynum;
	this->_steps = b._steps;
	this->_score = b._score;
	delete[] this->_emptylist;
	this->_emptylist = new COORD[this->_emptynum];
	for (i = 0; i < _emptynum; i++)
		this->_emptylist[i] = b._emptylist[i];

	return *this;
}

void Board::Init()
{
	delete[] _emptylist;
	COORD* ptr = nullptr;
	loop_control i, j;
	 _steps = _score = 0;
	_emptynum = this->_m*this->_n;
	ptr = this->_emptylist = new COORD[_emptynum];
	for (i = 0; i < this->_m; i++)
		for (j = 0; j < this->_n; j++)
		{
			_matptr[i][j] = 0;
			ptr->X = i; ptr->Y = j;
			ptr++;
		}

	AddBalls();
	AddBalls();
	AddBalls();
}


bool Board::Move(int8 x1, int8 y1, int8 x2, int8 y2)
{
	return false;
}

bool Board::AddBalls(bool animate)
{
	if (_emptynum == 0)return false;
	int8 rand_num = random(_emptynum), i = 0;
	COORD* c = _emptylist + rand_num;
	this->_matptr[c->X][c->Y] = random(EASY) + 1;
	_emptynum--;
	for (i = rand_num + 1; i <= _emptynum; i++)
		_emptylist[i - 1] = _emptylist[i];
	return true;
}

bool Board::GameOver()
{
	return false;
}

bool Board::_getPath()
{
	return false;
}
