#include "Owl.h"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;


Owl::Owl() {}

Owl::Owl(const std::string& name, const Location& loc) : Animal(name, loc)
{
	setType("Owl");
}


void Owl::step()
{
	int stepSize = 3;
	Location tmp = Location();
	Location loc = getLocation();

	if (loc.row == 3 || loc.row == 16 || loc.col == 3 || loc.col == 36)
		stepSize = 2;
	else if (loc.row <= 2 || loc.row >= 17 || loc.col <= 2 || loc.col >= 37)
		stepSize = 2;
	else
		stepSize = 3;

	switch (dir)
	{
	case downLeft:
		if (loc.col <= 3 || loc.row >= 16)
			dir = upRight;
		tmp.setCol(-stepSize);
		tmp.setRow(stepSize);
		break;

	case downRight:
		if (loc.col >= 36 || loc.row >= 16)
			dir = upLeft;
		tmp.setCol(stepSize);
		tmp.setRow(stepSize);
		break;

	case upLeft:
		if (loc.col <= 3 || loc.row <= 3)
			dir = downRight;
		tmp.setCol(-stepSize);
		tmp.setRow(-stepSize);
		break;

	case upRight:
		if (loc.col >= 36 || loc.row <= 3)
			dir = downLeft;
		tmp.setCol(stepSize);
		tmp.setRow(-stepSize);
		break;

	default:
		break;
	}
	setLocation(loc + tmp);
}

void Owl::move()
{
	Animal::move();
	int randomDir = dir;

	do{
		randomDir = rand() % 4;
	} while (randomDir == dir); // ensure direction change
	dir = randomDir;
}
