#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include <string>
using std::string;

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		void 	attack(const std::string& target);
		void 	guardGate();
};

#endif