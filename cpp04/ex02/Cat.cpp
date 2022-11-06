#include <string>
#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	_Brain = new class Brain();
	this->_type = "Cat";
	std::cout << "Cat constructor called \n";	
}
                                                                                  
Cat::~Cat()
{
	delete _Brain;
	std::cout << "Cat destructor called \n";
}


Cat::Cat(const Cat &src)
{
	this->_Brain = src._Brain;
}

Cat &Cat::operator=(const Cat& src)
{
	this->_Brain = src._Brain;
	std::cout << "Copy assignement operator called\n";
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miou miou je suis le chat\n";
}