#pragma once

#include "Animal.h"

class Owl : public Animal
{
private:
	int dir = 0;
	enum Dir { downLeft, downRight, upLeft, upRight};

public:
	Owl();
	Owl(const std::string& name, const Location& loc);

	void step() override;
	void move();
	void turnVertically() override {};
	void turnHorizontally() override {};
};
