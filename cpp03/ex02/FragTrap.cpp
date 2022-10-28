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

void 	FragTrap::highFivesGuys()
{
		std::cout << "Highfive!\n";
}