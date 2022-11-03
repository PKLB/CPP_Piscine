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

Dog::Dog(const Dog &src)
{
	this->_Brain = src._Brain;
}

Dog &Dog::operator=(const Dog& src)
{
	this->_Brain = src._Brain;
	std::cout << "Copy assignement operator called\n";
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Dog& src)
{
	os << src._Brain << std::endl;
    return os;
}

void Dog::makeSound() const
{
	std::cout << "wouaf wouaf je suis le chien\n";
}