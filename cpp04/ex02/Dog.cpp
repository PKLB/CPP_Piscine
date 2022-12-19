#include <string>
#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(){
	_Brain = new class Brain();
	this->_type = "Dog";
	std::cout << "Dog constructor called \n";	
}
                                                                                  
Dog::~Dog(){
	delete _Brain;
	std::cout << "Dog destructor called \n";
}

Dog::Dog(const Dog &src){
	this->_Brain = new Brain(*src._Brain);
 	this->_type = src._type;
	std::cout << "Dog copy constructor called \n";
}

Dog &Dog::operator=(const Dog& src){
	this->_Brain = new Brain(*src._Brain);
 	this->_type = src._type;
	std::cout << "Copy assignement operator called\n";
	return *this;
}

void Dog::makeSound() const{
	std::cout << "wouaf wouaf je suis le chien\n";
}

Brain *Dog::getBrain() const{
	return (this->_Brain);
}