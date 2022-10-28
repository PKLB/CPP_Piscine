#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap nono;

	std::cout << nono;
	nono.attack("ennemy");
	nono.setAttackDamage(20);
	nono.guardGate();

	std::cout << nono;
	return 0;
}