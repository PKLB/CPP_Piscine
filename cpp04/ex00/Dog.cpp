#include <string>
#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog constructor called \n";	
}
                                                                                  
Dog::~Dog()
{
	std::cout << "Dog destructor called \n";
}

void Dog::makeSound() const
{
	std::cout << "wouaf wouaf je suis le chien\n";
}