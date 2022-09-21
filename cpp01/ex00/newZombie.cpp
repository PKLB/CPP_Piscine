#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *toto = new Zombie;
	this->name = name;
    return (toto);
}
