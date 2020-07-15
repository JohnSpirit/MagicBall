//2019.8.27
#include "Controller.h"
int Controller::Size = 50;
int main(void)
{
	srand(time(0));
	Controller c(9, 9);
	c.Play();

	BALLTYPE b[] =
	{
		4,	5,	5,	5,	4,	5,	6,	0,	0,
		0,	4,	0,	6,	0,	0,	6,	0,	0,
		2,	0,	4,	3,	6,	0,	9,	4,	2,
		0,	2,	0,	4,	2,	6,	6,	0,	1,
		0,	4,	5,	0,	4,	0,	6,	0,	2,
		0,	4,	0,	0,	4,	4,	4,	6,	0,
		0,	0,	6,	0,	4,	0,	4,	0,	6,
		0,	0,	0,	0,	5,	0,	0,	4,	0,
		0,	0,	0,	0,	0,	0,	0,	0,	1
	};
	//BALLTYPE b[] =
	//{
	//	0,0,1,0,0,
	//	0,0,1,2,3,
	//	0,0,0,0,0,
	//	0,0,0,0,0,
	//	0,0,0,0,0
	//};
	Matrix<BALLTYPE> m(9,9);
	m.SetValueByArray(b,ALL);
	cout << m.TypeCast<int>();
	Board board(m);
	//cout << board.Move(1, 4, 4, 0) << endl;
	//cout << board._pathstack;
	cout << board.Check();
	system("pause");
	return 0;
}