#include"Zoo.h"
#include <string>
using std::cout;
using std::cin;
using std::endl;
 

Zoo::Zoo()
{
	Location loc;
	loc.setRow(rand() % ROWS);
	loc.setCol(rand() % COLUMNS);
	Lion* newLion = new Lion("Simba", loc);
	animals.push_back(newLion);
	loc.setRow(rand() % ROWS);
	loc.setCol(rand() % COLUMNS);
	Monkey* newMonkey = new Monkey("Rafiki", loc);
	animals.push_back(newMonkey);
	loc.setRow(rand() % ROWS);
	loc.setCol(rand() % COLUMNS);
	Owl* newOwl = new Owl("Hedwig", loc);
	animals.push_back(newOwl);
}

void Zoo::stop(int num)
{
	(*animals[num]).stop();
}

void Zoo::move(int num)
{
	if (!(*animals[num]).getIsMoving())
		(*animals[num]).move();
}

void Zoo::step()
{
	for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
		if ((*it)->getIsMoving())
			(*it)->step();
}

void Zoo::create(string type, string name)
{
	Location loc;
	loc.setRow(rand() % 20);
	loc.setCol(rand() % 40);
	if (type == "Lion")
	{
		Lion* newLion =  new Lion(name, loc);
		animals.push_back(newLion);
	}
	else if (type == "Monkey")
	{
		Monkey* newMonkey = new Monkey(name, loc);
		animals.push_back(newMonkey);
	}
	else if (type == "Owl")
	{
		Owl* newOwl = new Owl(name, loc);
		animals.push_back(newOwl);
	}
}

void Zoo::del(int num)
{
	animals.erase(animals.begin() + num);
}

void Zoo::delAll(string type)
{
	//for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
	//	if ((*it)->getType() == type)
	//		animals.erase(it);
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->getType() == type)
			animals.erase(animals.begin() + i);
}

void Zoo::help()
{
	cout << "Zoo program commands:" << endl;
	cout << "'stop <index>': Stop the animal at index <index> in from moving." << endl;
	cout << "'move <index>': Couse the animal at index <index> move." << endl;
	cout << "'create <animal type> <animal type>': Create a new animal of <animal name> <animal name>." << endl;
	cout << "'del <index>': Delete a specific animal from the animals list in the <index> index." << endl;
	cout << "'delAll <animal type>': Delete all animals of a specific type (<animal type>)" << endl;
	cout << "'help': Print help text." << endl;
	cout << "'exit': Exit the program." << endl;
	cout << "'.': Make the program advance without changing anything. All The animals in motion continue to move." << endl;
}

void Zoo::run()
{
	cout << "Walcome to the zoo!\n" << endl;
	cout << "The initially list of the animals in the zoo:\n" << endl;
	for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
		(*it)->printDetails();
	while (true)
	{
		cout << "\nPlease enter a command. To see the optional commands insert 'help'." << endl;
		string cmd, arg1, arg2;
		cin >> cmd;
		if (cmd == "crate")
		{
			cout << "Enter the animal's name:" << endl;
			cin >> arg1;
			cout << "Enter the animal's type" << endl;
			cin >> arg2;
			create(arg1, arg2);
		}
		if (cmd == "stop")
		{
			cout << "Enter the animal's index" << endl;
			stop(stoi(arg1));
			cin >> arg1;
		}
		else if (cmd == "move")
		{
			cout << "Enter the animal's index" << endl;
			cin >> arg1;
			move(stoi(arg1));
		}
		else if (cmd == "del")
		{
			cout << "Enter the animal's index" << endl;
			cin >> arg1;
			del(stoi(arg1));
		}
		else if (cmd == "delAll")
		{
			cout << "Enter the animal's type" << endl;
			cin >> arg1;
			delAll(arg1);
		}
		else if (cmd == "help")
			help();
		else if (cmd == "exit")
			break;
		else if (cmd == ".")
		{
			step();
			printAnimals();
			printBoard();
		}
		else
			cout << "Not a valid command! Please try again." << endl;
	}
	cout << "Good Bye!" << endl;
}

void Zoo::printAnimals()
{
	for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
		(*it)->printDetails();
}

void Zoo::printBoard()
{
	cout << "Zoo Map:" << endl;
	cout << "+--------------------------------------------------------------------------------+" << endl;
	for (int i = 0; i < ROWS; i++) {
		cout << "|";
		for (int j = 0; j < COLUMNS; j++) {
			bool foundAnimal = false;
			for (vector<Animal*>::iterator it = animals.begin(); it != animals.end() && !foundAnimal; it++) {
				if ((*it)->getLocation().getRow() == i && (*it)->getLocation().getCol() == j) {
					cout << (*it)->getInitial() << " ";
					foundAnimal = true;
				}
			}
			if (!foundAnimal) {
				cout << ". ";
			}
		}
		cout << "|" << endl;
	}
	cout << "+--------------------------------------------------------------------------------+" << endl;
}
