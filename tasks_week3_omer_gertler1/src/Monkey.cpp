#include "Monkey.h"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;


Monkey::Monkey() {}

Monkey::Monkey(const std::string& name, const Location& loc) : Animal(name, loc)
{
	setType("Monkey");
}

void Monkey::step()
{
	if (stepCounter % 5 == 0)
	{
		dir = rand() % 4;
		stepSize = (rand() % 2) + 1;
	}

	// change direction if the monkey on the border 
	turnHorizontally();
	turnVertically();
 
	if (stepSize != 2 || ((dir != right && dir != left && getLocation().col != 1 && getLocation().col != 38)
					  || (dir != up && dir != down && getLocation().row != 1 && getLocation().row != 18)))
	{
		switch (dir)
		{
		case down:
			setLocation(getLocation().row + stepSize, getLocation().col);
			break;

		case up:
			setLocation(getLocation().row - stepSize, getLocation().col);
			break;

		case right:
			setLocation(getLocation().row, getLocation().col + stepSize);
			break;

		case left:
			setLocation(getLocation().row, getLocation().col - stepSize);
			break;

		default:
			break;
		}
	}
	++stepCounter;
}

void Monkey::turnHorizontally()
{
	if (getLocation().col == 0 || getLocation().col ==1)
		dir = right;
	else if (getLocation().col == 39 || getLocation().col == 38)
		dir = left;
}

void Monkey::turnVertically()
{
	if (getLocation().row == 0 || getLocation().row == 1)
		dir = down;
	else if (getLocation().row == 19 || getLocation().row == 18)
		dir = up;
}
