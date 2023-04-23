#pragma once
//#include <string>
//#include <ostream>
#include "Location.h"

using std::string;
//using std::ostream;

class Animal
{
protected:

private:
	string name = "";
	string type = "";
	Location loc;
	bool isMoving = true;

public:
	Animal();
	Animal(const std::string& name, const Location& loc);

	void printDetails() const;
	char getInitial() const;
	Location getLocation() const;
	virtual void step() = 0;
	void stop();
	void move();
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;
	bool getIsMoving();
	void setLocation(int, int);
	void setLocation(Location location);

	string getType() const;
	void setType(const string animalType);
};
