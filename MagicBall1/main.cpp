//2019.8.27
#include "Controller.h"
int Controller::Size = 50;
int main(void)
{
	srand(time(0));
	Controller c(9, 9);
	c.InitBoard();
	c._board.Init();
	c.PrintBoard();

	system("pause");

	return 0;
}