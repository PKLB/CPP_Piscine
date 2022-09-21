#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

void    Zombie::randomChump( std::string name ){
	Zombie toto;
	toto.name = name;
    std::cout << toto.name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
