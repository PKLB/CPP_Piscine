#include <string>
#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat constructor called \n";	
}
                                                                                  
Cat::~Cat()
{
	std::cout << "Cat destructor called \n";
}

void Cat::makeSound() const
{
	std::cout << "miou miou je suis le chat\n";
}