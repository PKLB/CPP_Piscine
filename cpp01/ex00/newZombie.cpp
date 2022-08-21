#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *toto;
	//"this->" allows us to modify the private variable that has the same name than the parameter in this function
	this->name = name;
    return (toto);
}
