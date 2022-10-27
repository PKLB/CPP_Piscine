#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{

	if (this->_EnergyPoints > 0)
	{
		std::cout << "Claptrap" << _name << "attacks" << target << ", causing" << _AttackDamage << "points of damage !\n";
		&target.takeDamage(this->_AttackDamage);
		this->_EnergyPoints--;
	}
	else
		std::cout << "Not enough energy to attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_HitPoints -= amount;
	if (_HitPoints < 0)
		_HitPoints = 0;
	std::cout << "Claptrap" << _name << "lost " << amount << "point(s) of life !\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints > 0)
	{
		if (_HitPoints + amount > 10)
		{
			_HitPoints = 10;
			std::cout << "Claptrap" << _name << "is now full life!\n";
		}
		else if (amount <= 0)
			std::cout << "You cannot repair with this value !\n";
		else
		{
			_HitPoints += amount;
			std::cout << "Claptrap" << _name << "gained " << amount << "point(s) of life !\n";
		}
		this->_EnergyPoints--;
	}
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignement operator called\n";
	this->std::string _name;
	this->_HitPoints = src._HitPoints;
	this->_EnergyPoints = src._EnergyPoints;
	this->_AttackDamage = src._AttackDamage;
	return *this;
}