#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() :number(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src){
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called\n";
	this->number = src.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return this->number;
}

void Fixed::setRawBits(int const raw)
{
	this->number = raw;
}