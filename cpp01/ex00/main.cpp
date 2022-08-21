#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

int main()
{
    new Zombie;

	Zombie toto[3];
	//Creating a real zombie accessible from outside the function newZombie() scope
    toto[0].newZombie("🧟\033[1;32m Absolutely not a random chump\033[0m");
	//On the other hand this zombie is not allocated and is not accessible from here
    toto[1].randomChump("🧟 \033[1;33mRandom chump\033[0m");
	toto[0].announce();
	toto[1].announce();
	toto[2].newZombie("🧟\033[1;32m Bleroy\033[0m");
    return (0);
}