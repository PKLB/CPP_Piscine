#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

const string& Weapon::getType(){
	return (this->type);
}

const string Weapon::setType(string str){
	this->type = str;
	return (str);
}

Weapon::Weapon(string str){
	setType(str);
}

Weapon::~Weapon(){

}
