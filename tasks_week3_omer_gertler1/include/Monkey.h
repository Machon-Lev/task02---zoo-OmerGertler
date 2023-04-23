#pragma once
#include "Animal.h"

class Monkey : public Animal
{
private:
	int stepCounter = 0;
	int dir = 0;
	int stepSize = 0;
	enum Dir { down, up, right, left };

public:
	Monkey();
	Monkey(const std::string& name, const Location& loc);

	void step() override;
	void turnHorizontally() override;
	void turnVertically() override;
};
