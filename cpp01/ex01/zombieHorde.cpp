#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	//Allocating an array of N zombies

	for (int i = 0; i < N; i++)
		horde[i].newZombie(name);
	//I only need to change their name without allocating more memory (no "new" inside newZombie to avoid leaks)
	return (horde);
}

/*It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
pointer to the first zombie.
Implement your own tests to ensure your zombieHorde() function works as expected.
Try to call announce() for each one of the zombies.
Don’t forget to delete all the zombies and check for memory leaks.*/