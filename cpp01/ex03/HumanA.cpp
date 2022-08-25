#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

void HumanA::attack(){
	std::cout << name << " attacks with their \n";
}

HumanA::HumanA(string name, Weapon object) : weaponClass(object){
}
// -> Because WeaponObject is from another class I have to explicitly tell him to call his own constructor
// inside this constructor

HumanA::~HumanA(){
	
}
