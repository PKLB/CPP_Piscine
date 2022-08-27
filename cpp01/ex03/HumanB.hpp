#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

class   HumanB
{
    public:
		HumanB(string name);
		void setWeapon(Weapon object);
		Weapon	weaponClass;
		void attack();
		~HumanB();
    private:
        string 	name;
};

#endif