#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "\033[1;32mScavTrap default constructor called\033[0m\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1;31mScavTrap destructor called\033[0m\n";
}

ScavTrap::ScavTrap(ScavTrap const &src){
	std::cout << "Copy constructor called\n";
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "Copy assignement operator called\n";
	this->_name = src._name;
	setHitPoints(src._HitPoints);
	setEnergyPoints(src._EnergyPoints);
	setAttackDamage(src._AttackDamage);
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " is attacking " << target << ", causing " << _AttackDamage << " points of damage !\n";
		this->_EnergyPoints--;
	}
	else
		std::cout << "Attack failed!\n";
}

void 	ScavTrap::guardGate()
{
		std::cout << "ScavTrap is now in Gatekeeper mode!\n";
}