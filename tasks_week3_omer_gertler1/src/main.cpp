//zoo, omer gertler

#include "Zoo.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Zoo zoo;
	zoo.run();
}


// code to check the program:
/*
     Create a new zoo
    Zoo myZoo;

    // Print the initial list of animals
    std::cout << "Initial list of animals:" << endl;
    myZoo.printAnimals();

    // Stop and move animals
    cout << "\nStopping animal at index 0" << endl;
    myZoo.stop(0);

    cout << "Moving animal at index 1" << endl;
    myZoo.move(1);

    // Print list of animals after stopping and moving
    cout << "\nList of animals after stopping and moving:" << endl;
    myZoo.printAnimals();

    // Create a new animal and add it to the zoo
    cout << "\nCreating a new Lion named Simba" << endl;
    myZoo.create("Lion", "Simba");

    // Print the list of animals after creating a new animal
    cout << "\nList of animals after creating a new Lion:" << endl;
    myZoo.printAnimals();

    // Delete an animal from the zoo
    cout << "\nDeleting animal at index 1" << endl;
    myZoo.del(1);

    // Print the list of animals after deleting an animal
    cout << "\nList of animals after deleting an animal:" << endl;
    myZoo.printAnimals();

    // Delete all animals of a specific type
    cout << "\nDeleting all Owls" << endl;
    myZoo.delAll("Owl");

    // Print the list of animals after deleting all animals of a specific type
    cout << "\nList of animals after deleting all Owls:" << endl;
    myZoo.printAnimals();

    // Print the help text
    cout << "\nHelp text:" << endl;
    myZoo.help();

    // Step through the simulation
    cout << "\nStepping through the simulation:" << endl;
    myZoo.step();
    myZoo.printAnimals();

    // Run the zoo program
    cout << "\nRunning the zoo program:" << endl;
    myZoo.run();
    */

