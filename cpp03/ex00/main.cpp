#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap test = ClapTrap("Toto");

	std::cout << test;
	test.attack("ennemy");
	test.takeDamage(test.getAttackDamage());
	test.beRepaired(2);
	std::cout << test;
	// test.setAttackDamage(4);
	// test.takeDamage(test.getAttackDamage());
	// std::cout << test;

	return 0;
}