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
		HumanA(string name, Weapon &object);
		void attack();
		~HumanA();
    private:
		Weapon	&weaponClass;
        string 	name;
};
//using a reference so if the weapon is modified, HumanA will be able to access the change
#endif