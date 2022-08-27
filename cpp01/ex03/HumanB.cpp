#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

void HumanB::setWeapon(Weapon object){
	this->weapon = object.getType();
}

void HumanB::attack(){
	std::cout << name << " attacks with their " << weapon << "\n";
}

HumanB::HumanB(string name){
	this->name = name;
}


HumanB::~HumanB(){
	
}