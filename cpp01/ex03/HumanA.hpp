#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

class   HumanA
{
    public:
		HumanA(string name, Weapon object);
		Weapon	weaponClass;
		void attack();
		~HumanA();
    private:
        string 	name;
};

#endif