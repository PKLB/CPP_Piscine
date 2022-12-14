#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(): _name("Default name")
{
	std::cout << "\033[1;32mDefault constructor called\033[0m\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "\033[1;32mConstructor called\033[0m\n";
}

ClapTrap::ClapTrap(ClapTrap const &src){
	std::cout << "Copy constructor called\n";
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[1;31mDestructor called\033[0m\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignement operator called\n";
	this->_name = src._name;
	setHitPoints(src._HitPoints);
	setEnergyPoints(src._EnergyPoints);
	setAttackDamage(src._AttackDamage);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& src)
{
    os << "\033[1;36m[" << src.getName() << "] \033[1;32mHP[" << src.getHitPoints() << "] \033[1;33mENERGY[" << src.getEnergyPoints() << "] \033[1;34mATK[" << src.getAttackDamage() << "]\033[0m\n";
    return os;
}

string ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHitPoints() const
{
	return (this->_HitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->_EnergyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->_AttackDamage);
}

void ClapTrap::setHitPoints(int nb) 
{
	this->_HitPoints = nb;
}

void ClapTrap::setEnergyPoints(int nb) 
{
	this->_EnergyPoints = nb;
}

void ClapTrap::setAttackDamage(int nb) 
{
	this->_AttackDamage = nb;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		std::cout << "Claptrap " << _name << " is attacking " << target << ", causing " << _AttackDamage << " points of damage !\n";
		this->_EnergyPoints--;
	}
	else
		std::cout << "Attack failed!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_HitPoints -= amount;
	if (_HitPoints < 0)
		_HitPoints = 0;
	std::cout << "Claptrap " << _name << " lost " << amount << " point(s) of life !\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		if (_HitPoints + amount >= 10)
		{
			_HitPoints = 10;
			std::cout << "Claptrap " << _name << " is full life!\n";
		}
		else if (amount <= 0)
			std::cout << "You cannot repair with this value !\n";
		else
		{
			_HitPoints += amount;
			if (_HitPoints > 10)
				_HitPoints = 10;
			std::cout << "Claptrap " << _name << " gained " << amount << " point(s) of life !\n";
		}
		this->_EnergyPoints--;
	}
	else
		std::cout << "Reparation failed\n";
}
