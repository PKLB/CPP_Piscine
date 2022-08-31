#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

void HumanB::setWeapon(Weapon &object){
	weaponClass = &object;
	//weaponClass->setType(object.getType());
}

void HumanB::attack(){
	if (weaponClass != NULL)
		std::cout << name << " attacks with their " <<  weaponClass->getType() << "\n";
	else
		std::cout << "i have no weapon bohooooo\n";
}

HumanB::HumanB(string name) : weaponClass(NULL){
	this->name = name;
}

HumanB::~HumanB(){

}
