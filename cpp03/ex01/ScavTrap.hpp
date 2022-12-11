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
		ScavTrap(ScavTrap const &src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap& src);

		void 	attack(const std::string& target);
		void 	guardGate();
};

#endif