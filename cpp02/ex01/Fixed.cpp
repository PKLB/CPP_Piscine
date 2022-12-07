#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <string>

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed() : _number(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src) : _number(src._number) {
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const float src) : _number(roundf(src * 256.0)) {
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const int src): _number(src << _bitNumber){
	std::cout << "Int constructor called\n";
}

int 	Fixed::getRawBits(void) const{
	return(this->_number);
}

void 	Fixed::setRawBits(int const raw){
	this->_number = raw;
}

float 	Fixed::toFloat (void) const{
	return (_number / 256.0);
}

int		Fixed::toInt (void) const{
	return (_number / 256);
}

std::ostream& operator<<(std::ostream& os, Fixed const& src){
    os << src.toFloat();
    return os;
}

Fixed &Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignement operator called\n";
	_number = src._number;
	return *this;
}
