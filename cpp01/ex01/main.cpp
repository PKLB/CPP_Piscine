#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

int main()
{
	Zombie *toto = new Zombie[5];

	//"new" alone will create a instance while "new[]" will create an N-element array
	toto = toto->zombieHorde(5, "\033[1;34mPizza-guy 🍕\033[0m");
	for (int i = 0; i < 5; i++)
		toto[i].announce();
	delete[] toto;
	//i have to use "delete[]" so the destructor is called N-times to destroy each element in the array
    return (0);
}