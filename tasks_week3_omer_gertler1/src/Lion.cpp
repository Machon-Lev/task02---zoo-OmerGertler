#include "Lion.h"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

Lion::Lion() {}

Lion::Lion(const std::string& name, const Location& loc) : Animal(name, loc)
{
	setType("Lion");
}

void Lion::step()
{
	if (getIsMoving())
	{
		int newCol = getLocation().col;
		if (isMovingRight)
		{
			if (newCol == 38)
			{
				turnHorizontally();
				newCol -= 2;
			}
			else if (newCol == 37)
				turnHorizontally();
			else
				newCol += 2;
		}
		else
		{
			if (newCol == 1)
			{
				turnHorizontally();
				newCol += 2;
			}
			else if (newCol == 2)
				turnHorizontally();
			else
				newCol -= 2;
		}
		setLocation(getLocation().row, newCol);
	}

}

void Lion::turnHorizontally()
{
	if (isMovingRight)
		isMovingRight = false;
	else
		isMovingRight = true;
}

void Lion::move()
{
	Animal::move();
	int random_int = rand() % 2;
	isMovingRight = (random_int == 1);
}
