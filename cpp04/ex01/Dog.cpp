#include <string>
#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	_Brain = new class Brain();
	this->_type = "Dog";
	std::cout << "Dog constructor called \n";	
}
                                                                                  
Dog::~Dog()
{
	delete _Brain;
	std::cout << "Dog destructor called \n";
}

void Dog::makeSound() const
{
	std::cout << "wouaf wouaf je suis le chien\n";
}