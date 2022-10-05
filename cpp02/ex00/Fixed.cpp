#include "Fixed.hpp"
#include <iostream>

void Fixed::setRawBits(int value)
{
	number = value;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (number);
}

Fixed &Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called\n";
	number = src.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::Fixed() :number(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}