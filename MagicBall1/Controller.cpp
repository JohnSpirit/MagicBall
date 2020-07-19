#include "Controller.h"


Controller::Controller(int x, int y, int mode) :_x(x), _y(y), _board(x, y, mode)
{
	srand(time(0));
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
			if (this->_getCommand())
			{
				if (this->_board._pathstack._nowlen >= 0)
				{
					int fps = 300 / this->_board._pathstack._nowlen;
					BALLTYPE b = this->_board._pathstack[0].bt;
					for (loop_control i = 0; i < this->_board._pathstack._nowlen; i++)
					{//animation
						_drawBall(this->_board._pathstack[i].cd, 0);
						_drawBall(this->_board._pathstack[i + 1].cd, b);
						Sleep(fps);
					}
				}
				if (!this->_board.Check())
				{
					for (loop_control i = 0; i < 3; i++)
					{
						Sleep(50);
						this->_board.AddBalls();
						this->_printBoard();
					}
				}
			}
			this->_board.Check();
			this->_printBoard();
		}
	}
}

void Controller::_initBoard()
{
	initgraph(Size*(_x + 3 + 1.5), Size*(_y + 1),1);

	setorigin(0, 0);
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(200, 200, 200));
	cleardevice();

	setorigin(0.5*Size, 0.5*Size);
	loop_control i, j;
	for (i = 0; i < _x; i++)
		for (j = 0; j < _y; j++)_drawBall(i, j);
	_updateScore();
}

void Controller::_printBoard()
{
	setorigin(0.5*Size, 0.5*Size);
	loop_control i, j;
	for (i = 0; i < _x; i++)
		for (j = 0; j < _y; j++)_drawBall(i, j, this->_board._getMatptr()[i][j]);
	_updateScore();
}

void Controller::_drawBall(int x, int y, BALLTYPE type)
{
	setfillcolor((x + y) % 2 ? RGB(50, 50, 50) : BLACK);
	//clearrectangle(x*Size, y*Size, x*Size + Size, y*Size + Size);
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
	case 7:setfillcolor(RGB(255, 128, 0)); break;
	}
	solidcircle(x*Size + 0.5*Size, y*Size + 0.5*Size, 0.45*Size);
}

void Controller::_drawBall(Coord c, BALLTYPE type)
{
	_drawBall(c.X, c.Y, type);
}

void Controller::_selectBall(int x, int y)
{
	int lw = 4;
	setlinestyle(PS_SOLID, lw);
	setlinecolor(RED);
	rectangle(x*Size + (lw >> 1), y*Size + (lw >> 1), x*Size + Size - (lw >> 1), y*Size + Size - (lw >> 1));
}

void Controller::_selectBall(Coord c)
{
	_selectBall(c.X, c.Y);
}

void Controller::_updateScore()
{
	char ssteps[8] = "\0", sscore[8] = "\0";
	sprintf(ssteps, "%d", this->_board._steps);
	sprintf(sscore, "%d", this->_board._score);

	setorigin((0.5 + _y)*Size, 0.5*Size);
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(150, 150, 150));
	clearrectangle(0.5*Size, 0.5*Size, 2.5*Size + Size, Size + Size);
	RECT pRect1 = { 0.5*Size, 0.5*Size, 2.5*Size + Size, Size + Size };
	settextcolor(RGB(255, 255, 255));
	LOGFONT font;
	gettextstyle(&font);
	strcpy(font.lfFaceName, _T("ËÎÌו"));
	font.lfHeight = 1 * Size;
	font.lfWidth = 0;
	font.lfQuality = PROOF_QUALITY;
	settextstyle(&font);
	//drawtext(this->_board._steps, &pRect1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(sscore, &pRect1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setorigin(0.5*Size, 0.5*Size);
}

bool Controller::_getCommand()
{
	MOUSEMSG m;
	Coord selected_balls[2] = { Coord(-10,-10),Coord(-100,-100) };
	int selected_ball_count = 0;

	while (selected_ball_count < 2)
	{
		while (!(m = GetMouseMsg()).mkLButton)Sleep(1);
		selected_balls[selected_ball_count ? 0 : 1] =
			Coord(int8((m.x - 0.5*Size - (m.x - int(0.5*Size)) % Size) / Size),
				int8((m.y - 0.5*Size - (m.y - int(0.5*Size)) % Size) / Size));
		if (m.x >= (0.5 + _x)*Size || m.y >= (0.5 + _y)*Size)continue;
		_selectBall(selected_balls[selected_ball_count ? 0 : 1].X, selected_balls[selected_ball_count ? 0 : 1].Y);
		selected_ball_count++;
		if (selected_balls[0] == selected_balls[1])
		{
			selected_ball_count = 0;
			_drawBall(selected_balls[0].X, selected_balls[0].Y,
				this->_board._getMatptr()[selected_balls[0].X][selected_balls[0].Y]);
			selected_balls[0] = Coord(-10, -10), selected_balls[1] = Coord(-100, -100);
		}
		//cout << selected_ball_count << "\t";
		while (GetMouseMsg().mkLButton)Sleep(1);
	}
	return this->_board.Move(selected_balls[1], selected_balls[0]);
}
