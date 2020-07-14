#include "Board.h"


Board::Board() :Matrix<BALLTYPE>(), _pathstack(0)
{

}

Board::Board(int x, int y) : Matrix<BALLTYPE>(x, y), _emptynum(x*y), _pathstack(x*y)
{
	Coord* ptr = nullptr;
	loop_control i, j;
	ptr = this->_emptylist = new Coord[this->_emptynum];
	for (i = 0; i < this->_m; i++)
		for (j = 0; j < this->_n; j++)
		{
			_matptr[i][j] = 0;
			ptr->X = i; ptr->Y = j;
			ptr++;
		}
}

Board::Board(const Matrix<BALLTYPE>& b) :Matrix<BALLTYPE>(b),_pathstack(b.GetSize(0)*b.GetSize(1))
{

}

Board::Board(const Board & b) :
	Matrix<BALLTYPE>(b), _score(b._score), _steps(b._steps), _emptynum(b._emptynum), _pathstack(b.GetSize(0)*b.GetSize(1))
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
	this->_emptylist = new Coord[this->_emptynum];
	for (i = 0; i < _emptynum; i++)
		this->_emptylist[i] = b._emptylist[i];

	return *this;
}

void Board::Init()
{
	delete[] _emptylist;
	Coord* ptr = nullptr;
	loop_control i, j;
	_steps = _score = 0;
	_emptynum = this->_m*this->_n;
	ptr = this->_emptylist = new Coord[_emptynum];
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
	if (this->_matptr[x2][y2])return false;
	else return _getPath(x1, y1, x2, y2);
}

bool Board::Move(const Coord & from, const Coord & to)
{
	return Move(from.X, from.Y, to.X, to.Y);
}

bool Board::AddBalls(bool animate)
{
	if (_emptynum == 0)return false;
	int8 rand_num = random(_emptynum), i = 0;
	Coord* c = _emptylist + rand_num;
	this->_matptr[c->X][c->Y] = random(EASY) + 1;
	_emptynum--;
	for (i = rand_num + 1; i <= _emptynum; i++)
		_emptylist[i - 1] = _emptylist[i];
	return true;
}

bool Board::GameOver()
{
	return !_emptynum;
}

bool Board::Check()
{
	
	loop_control i = _min_balls - 1, j = 0, end = 0, counter = 1;
	BALLTYPE b = this->_matptr[_min_balls - 1][j];
	//y向
	for (j = 0; j < this->_n; j++)
	{
		end = _min_balls - 1, counter = 1, i = 1 , b = this->_matptr[0][j];
		while (true)
		{
			for (; i <=end; i++)
			{
				if (this->_matptr[i][j] == b)counter++;
				else break;
			}
			if (counter == _min_balls && b)
			{
				_balls_to_remove.bt = b;
				_balls_to_remove.cd = Coord(i , j);
				_balls_to_remove.dir = LEFT;
				return true;
			}
			else if (i + 4 >= _m)break;
			else
			{
				counter = 1;
				b = this->_matptr[i][j];
				end = i + 4;
				i += 1;
			}
		}
	}

	//x向
	for (j = 0; j < this->_m; j++)
	{
		end = _min_balls - 1, counter = 1, i = 1, b = this->_matptr[j][0];
		while (true)
		{
			for (; i <= end; i++)
			{
				if (this->_matptr[j][i] == b)counter++;
				else break;
			}
			if (counter == _min_balls && b)
			{
				_balls_to_remove.bt = b;
				_balls_to_remove.cd = Coord(j, i);
				_balls_to_remove.dir = LEFT;
				return true;
			}
			else if (i + 4 >= _n)break;
			else
			{
				counter = 1;
				b = this->_matptr[j][i];
				end = i + 4;
				i += 1;
			}
		}
	}
	//斜向右下

		
	return false;
}

bool Board::_getPath(int8 x1, int8 y1, int8 x2, int8 y2)
{
	DIR dir = 0;
	BALLTYPE sniff_num = -1;
	Coord sniff_coord;
	StackNode dest(x2, y2, this->_matptr[x2][y2], -1);
	this->_pathstack.Reset();
	this->_pathstack.Push(x1, y1, this->_matptr[x1][y1]);

	while (true)
	{
		if (this->_pathstack[-1].dir < 5)
		{
			sniff_num = _sniff(this->_pathstack[-1].cd, this->_pathstack[-1].dir);
			sniff_coord = _sniff_coord(this->_pathstack[-1].cd, this->_pathstack[-1].dir);
			if (sniff_num || (this->_pathstack._nowlen == 0 ? false : this->_pathstack[-1].dir == REV(this->_pathstack[-2].dir)))
				//如果该方向非空或该方向为来时方向，跳过。
				this->_pathstack[-1].dir++;
			else if (dir = this->_pathstack[-1].cd.adj(dest.cd))//相邻
			{
				this->_pathstack.Push(x2, y2, this->_matptr[x2][y2]);
				this->_pathstack[-1].dir = dir;
				break;
			}
			//如果被嗅探坐标为已走过路径，则跳过。
			else if(this->_pathstack.Has(sniff_coord))this->_pathstack[-1].dir++;
			else this->_pathstack.Push(sniff_coord, sniff_num);
		}
		else this->_pathstack.Pop();

		if (this->_pathstack._nowlen == -1)return false;
	}

	return true;
}

BALLTYPE Board::_sniff(Coord c, DIR dir)
{
	switch (dir)
	{
	case LEFT:
		return c.X >= 1 ? this->_matptr[c.X - 1][c.Y] : -1;
	case UP:
		return c.Y >= 1 ? this->_matptr[c.X][c.Y - 1] : -1;
	case DOWN:
		return c.Y < this->_n - 1 ? this->_matptr[c.X][c.Y + 1] : -1;
	case RIGHT:
		return c.X < this->_m - 1 ? this->_matptr[c.X + 1][c.Y] : -1;
	default:
		return -1;
	}
	
}

Coord Board::_sniff_coord(Coord c, DIR dir)
{
	switch (dir)
	{
	case LEFT:
		return c.X >= 1 ? Coord(c.X - 1, c.Y) : Coord(-1, -1);
	case UP:
		return c.Y >= 1 ? Coord(c.X, c.Y - 1) : Coord(-1, -1);
	case DOWN:
		return c.Y < this->_n - 1 ? Coord(c.X, c.Y + 1) : Coord(-1, -1);
	case RIGHT:
		return c.X < this->_m - 1 ? Coord(c.X + 1, c.Y) : Coord(-1, -1);
	default:
		return Coord(-1, -1);
	}
}
