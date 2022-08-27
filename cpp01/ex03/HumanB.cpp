#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

void setWeapon(Weapon object){

}

void HumanB::attack(){
	std::cout << name << " attacks with their \n";
}

HumanB::HumanB(string name) : weaponClass(""){
}
// -> Because WeaponObject is from another class I have to explicitly tell him to call his own constructor
// inside this constructor

HumanB::~HumanB(){
	
}