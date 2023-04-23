#pragma once
#include "Location.h"
#include"Lion.h"
#include"Monkey.h"
#include"Owl.h"
#include <vector>
using std::string;
using std::vector;

#define ROWS 20
#define COLUMNS 40

class Zoo
{
//private:
public:
	vector<Animal*> animals;

	void stop(int num);
	void move(int num);
	void step();
	void create(string type, string name);
	void del(int num);
	void delAll(string type);
	void help();

	void printAnimals();
	void printBoard();

public:
	Zoo();
	void run();
};