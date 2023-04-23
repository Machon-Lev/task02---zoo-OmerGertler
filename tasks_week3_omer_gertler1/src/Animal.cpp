#include <Animal.h>
#include <iostream>
using std::cout;
using std::endl;

Animal::Animal() 
{
	this->loc.col = 0;
	this->loc.row = 0;
}

Animal::Animal(const std::string& name, const Location& loc)
{
	this->name = name;
	this->loc = loc;
	//this->type = typeid(this).name();
}

//----------------------------------

void Animal::printDetails() const
{
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Location: " << loc << endl << endl;
}

char Animal::getInitial() const
{
	return type[0];
}

Location Animal::getLocation() const
{
	return loc;
}

void Animal::stop()
{
	isMoving = false;
}

void Animal::move()
{
	isMoving = true;
}

bool Animal::getIsMoving()
{
	return isMoving;
}

void Animal::setLocation(int newRow, int newCol)
{
	loc.setRow(newRow);
	loc.setCol(newCol);
}

void Animal::setLocation(Location location)
{
	loc = location;
}

string Animal::getType() const
{
	return type;
}

void Animal::setType(const string animalType) 
{
	type = animalType;
}

