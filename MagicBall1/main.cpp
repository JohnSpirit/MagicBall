//2019.8.27
#include "Controller.h"
int Controller::Size = 50;
int main(void)
{
	srand(time(0));
	Controller c(9, 9);
	c.Play();
	//BALLTYPE b[] =
	//{
	//	1,2,3,3,3,0,3,5,4,
	//	6,0,0,0,0,0,0,0,0,
	//	5,0,0,0,0,0,0,0,0,
	//	5,0,0,0,0,0,0,0,0,
	//	5,0,0,0,0,0,0,0,0,
	//	5,0,0,0,0,0,0,0,0,
	//	5,0,0,0,0,0,0,0,0,
	//	4,0,0,0,0,0,0,0,0,
	//	5,0,0,0,0,0,0,0,0
	//};
	//Matrix<BALLTYPE> m(9,9);
	//m.SetValueByArray(b,ALL);
	//cout << m.TypeCast<int>();
	//Board board(m);
	//cout << board.Check();
	system("pause");
	return 0;
}