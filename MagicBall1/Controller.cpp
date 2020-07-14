#include "Controller.h"


Controller::Controller(int x, int y) :_x(x), _y(y), _board(x, y)
{

}

Controller::~Controller()
{
	closegraph();
}

void Controller::Play()
{
	this->_initBoard();
	while (true)
	{
		this->_board.Init();
		this->_printBoard();
		while (!this->_board.GameOver())
		{
			if (this->_getCommand())this->_printBoard();
		}
	}
}

void Controller::_initBoard()
{
	initgraph(Size*(_x + 3 + 1.5), Size*(_y + 1), 1);

	setorigin(0, 0);
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(200, 200, 200));
	cleardevice();

	setorigin(0.5*Size, 0.5*Size);
	loop_control i, j;
	for (i = 0; i < _x; i++)
		for (j = 0; j < _y; j++)_drawBall(i, j);

	_updateScore(0);
}

void Controller::_printBoard()
{
	setorigin(0.5*Size, 0.5*Size);
	loop_control i, j;
	for (i = 0; i < _x; i++)
		for (j = 0; j < _y; j++)_drawBall(i, j, this->_board._getMatptr()[i][j]);
	_updateScore(0);
}

void Controller::_drawBall(int x, int y, BALLTYPE type)
{
	setfillcolor((x + y) % 2 ? RGB(50, 50, 50) : BLACK);
	solidrectangle(x*Size, y*Size, x*Size + Size, y*Size + Size);
	switch (type)
	{
	case 0:break;
	case 1:setfillcolor(BLUE); break;
	case 2:setfillcolor(RED); break;
	case 3:setfillcolor(YELLOW); break;
	case 4:setfillcolor(GREEN); break;
	case 5:setfillcolor(CYAN); break;
	case 6:setfillcolor(MAGENTA); break;
	case 7:setfillcolor(LIGHTGRAY); break;
	}
	solidcircle(x*Size + 0.5*Size, y*Size + 0.5*Size, 0.45*Size);
}

void Controller::_selectBall(int x, int y)
{
}

void Controller::_updateScore(int score)
{
}

bool Controller::_getCommand()
{
	MOUSEMSG m;
	Coord selected_balls[2] = { Coord(-10,-10),Coord(-100,-100) };
	int selected_ball_count = 0;

	while (selected_ball_count < 2)
	{
		while (!(m = GetMouseMsg()).mkLButton)Sleep(1);
		selected_balls[selected_ball_count ? 1 : 0] = 
			Coord(int8((m.x - 0.5*Size - (m.x - int(0.5*Size)) % Size) / Size), 
				int8((m.y - 0.5*Size - (m.y - int(0.5*Size)) % Size) / Size));
		//_selectBall(selected_balls[selected_ball_count ? 0 : 1].X, selected_balls[selected_ball_count ? 0 : 1].Y);
		selected_ball_count++;
		if (selected_balls[0] == selected_balls[1])selected_ball_count--;
		cout << selected_ball_count << "\t";
		while (GetMouseMsg().mkLButton)Sleep(1);
	}
	return this->_board.Move(selected_balls[0], selected_balls[1]);
}
