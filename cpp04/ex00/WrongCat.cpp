#include <string>
#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat constructor called \n";	
}
                                                                                  
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called \n";
}

void WrongCat::makeSound() const
{
	std::cout << "miou miou je suis le chat\n";
}