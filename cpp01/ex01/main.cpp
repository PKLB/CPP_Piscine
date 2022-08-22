#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

int main()
{
	Zombie *toto = new Zombie;

	toto = toto->zombieHorde(5, "Pizza-guy");
	for (int i = 0; i < 5; i++)
		toto[i].announce();
	delete toto;
    return (0);
}