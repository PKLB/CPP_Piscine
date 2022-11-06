#include <string>
#include <iostream>
#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal constructor called \n";	
}

Animal::Animal(string src): _type(src)
{
	std::cout << "Animal constructor called \n";	
}
                                                                                  
Animal::~Animal()
{
	std::cout << "Animal destructor called \n";
}

Animal::Animal(const Animal &src)
{
	this->_type = src._type;
}

Animal &Animal::operator=(const Animal& src)
{
	std::cout << "Copy assignement operator called\n";
	this->_type = src._type;
	return *this;
}

string	Animal::getType() const
{
	return(this->_type);
}

void	Animal::setType(string src)
{
	this->_type = src;
}

void Animal::makeSound() const
{
	std::cout << "kwak kwak\n";
}