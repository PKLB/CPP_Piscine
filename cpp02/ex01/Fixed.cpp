#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed() : _number(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src) : _number(src._number) 
{
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const float src) : _number(roundf(src * (1 << _bitNumber))) 
{
	std::cout << "Float constructor called\n";
}
// A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.

Fixed::Fixed(const int src) : _number(src << _bitNumber) 
{
	std::cout << _number << std::endl;
	std::cout << "Int constructor called\n";
}
// A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.




int 	Fixed::getRawBits(void)
{
	return(this->_number);
}

void 	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

float 	Fixed::toFloat (void) const
{
	return (_number);
}
// A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.

int		Fixed::toInt (void) const
{
	return (_number);
}
// A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value.

std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
    os << src._number;
    return os;
}
// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.

Fixed &Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignement operator called\n";
	_number = src._number;
	return *this;
}
