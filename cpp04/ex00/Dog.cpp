#include <string>
#include <iostream>
#include "Dog.hpp"

Dog::Dog(){
	this->_type = "Dog";
	std::cout << "Dog constructor called \n";	
}

Dog::~Dog(){
	std::cout << "Dog destructor called \n";
}

Dog::Dog(const Dog &src){
	*this = src;
}

Dog &Dog::operator=(const Dog& src){
	std::cout << "Copy assignement operator called\n";
	this->_type = src._type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "wouaf wouaf je suis le chien\n";
}