#include "Zombie.hpp"
#include <iostream>
#include <string>
using std::string;

void	Zombie::announce( void )
{
	if (name.length() <= 0)
		std::cout << "🧟 \033[1;31mUnknown Zombie\033[0m" << ": BraiiiiiiinnnzzzZ..." <<std::endl;
	else
		std::cout << name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	//from what I've understood the destructor will automatically free the object
	if (name.length() <= 0)
		std::cout << "🧟 \033[1;31mUnknown Zombie\033[0m:" << " has been deleted." <<std::endl;
	else
		std::cout << name << " has been deleted." << std::endl;
}
