#include "Controller.h"


Controller::Controller(int x, int y) :_x(x), _y(y), _board(x, y)
{

}

Controller::~Controller()
{
	closegraph();
}

void Controller::InitBoard()
{
	initgraph(Size*(_x + 3 + 1.5), Size*(_y + 1), 1);

	setorigin(0, 0);
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(200, 200, 200));
	cleardevice();

	setorigin(0.5*Size, 0.5*Size);
	loop_control i, j;
	for (i = 0; i < _x; i++)
		for (j = 0; j < _y; j++)DrawBall(i, j);

	UpdateScore(0);
}

void Controller::PrintBoard()
{
	setorigin(0.5*Size, 0.5*Size);
	loop_control i, j;
	for (i = 0; i < _x; i++)
		for (j = 0; j < _y; j++)DrawBall(i, j,this->_board._getMatptr()[i][j]);
	UpdateScore(0);
}

void Controller::DrawBall(int x, int y, BALLTYPE type)
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

void Controller::UpdateScore(int score)
{
}
