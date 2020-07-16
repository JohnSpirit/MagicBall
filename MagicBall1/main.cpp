//2019.8.27
#include "Controller.h"
int Controller::Size = 60;
int main(void)
{
	Controller c(9, 9, HARD);
	c.Play();
	return 0;
}