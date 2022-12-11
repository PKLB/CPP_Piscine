#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "\033[1;32mFragTrap default constructor called\033[0m\n";
}

FragTrap::~FragTrap()
{
	std::cout << "\033[1;31mFragTrap destructor called\033[0m\n";
}

FragTrap::FragTrap(FragTrap const &src){
	std::cout << "Copy constructor called\n";
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap& src)
{
	std::cout << "Copy assignement operator called\n";
	this->_name = src._name;
	setHitPoints(src._HitPoints);
	setEnergyPoints(src._EnergyPoints);
	setAttackDamage(src._AttackDamage);
	return *this;
}

void 	FragTrap::highFivesGuys()
{
		std::cout << "Highfive!\n";
}