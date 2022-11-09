#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() :number(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}