#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

const string& Weapon::getType(){
	return (type);
}

const string Weapon::setType(string str){
	type = str;
	return (str);
}

Weapon::Weapon(){

}

Weapon::~Weapon(){
	
}
