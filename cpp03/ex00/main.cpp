#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap test = ClapTrap("Toto");

	std::cout << test;
	test.attack("ennemy");
	test.takeDamage(5);
	test.beRepaired(2);

	std::cout << test;
	return 0;
}