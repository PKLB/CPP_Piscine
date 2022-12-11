#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include <string>
using std::string;

class	FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &src);
		~FragTrap();
		FragTrap &operator=(const FragTrap& src);

		void highFivesGuys(void);
};

#endif