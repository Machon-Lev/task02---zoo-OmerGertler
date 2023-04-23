#pragma once
#include "Animal.h"

class Lion : public Animal
{
private:
	bool isMovingRight = true;

public:
	Lion();
	Lion(const std::string& name, const Location& loc);

	void step() override;
	void turnVertically() override {};
	void turnHorizontally() override;
	void move();
};

