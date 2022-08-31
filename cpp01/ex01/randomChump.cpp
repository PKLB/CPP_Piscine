#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

void    Zombie::randomChump( std::string name ){
	Zombie toto;
	toto.name = name;
    std::cout << toto.name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
//"It creates a zombie, name it, and the zombie announces itself."
//^ this means that there is no need to allocate the zombie in the memory 