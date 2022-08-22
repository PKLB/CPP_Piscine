#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

void    Zombie::randomChump( std::string name ){
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
//"It creates a zombie, name it, and the zombie announces itself."
//^ this means that there is no need to allocate the zombie in the memory 