#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap nono;

	std::cout << nono;
	nono.attack("ennemy");
	nono.setAttackDamage(20);
	nono.highFivesGuys();

	std::cout << nono;
	return 0;
}