#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal default constructor called \n";	
}

WrongAnimal::WrongAnimal(string src): _type(src){
	std::cout << "WrongAnimal constructor called \n";	
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called \n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
		*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& src){
	std::cout << "Copy assignement operator called\n";
	this->_type = src._type;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const WrongAnimal& src){
    os << src.getType() << "\n";
    return os;
}

string	WrongAnimal::getType() const{
	return(this->_type);
}

void	WrongAnimal::setType(string src){
	this->_type = src;
}

void WrongAnimal::makeSound() const{
	std::cout << "SIUUUUUUUUU\n";
}