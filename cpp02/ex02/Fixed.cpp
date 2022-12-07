#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <string>

Fixed::~Fixed(){
	//std::cout << "Destructor called\n";
}

Fixed::Fixed() : _number(0) {
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &src) : _number(src._number) {
	//std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const float src) : _number(roundf(src * 256.0)) {
	//std::cout << "Float constructor called\n";
}

Fixed::Fixed(const int src): _number(src << _bitNumber){
	//std::cout << "Int constructor called\n";
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
	//std::cout << "Copy assignement operator called\n";
	_number = src._number;
	return *this;
}

Fixed &Fixed::operator++(){
	_number += 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	operator++();
	return temp;
}

Fixed &Fixed::operator--(){
	_number -= 1;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	operator--();
	return temp;
}

Fixed &Fixed::operator+=(const Fixed&src){
	this->_number = this->getRawBits() + src.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed&src){
	Fixed temp = *this;
	temp += src;
	return temp;
}

Fixed &Fixed::operator-=(const Fixed&src){
	this->_number = this->getRawBits() - src.getRawBits();
	return *this;
}

Fixed Fixed::operator-(const Fixed&src){
	Fixed temp = *this;
	temp -= src;
	return temp;
}

Fixed &Fixed::operator*=(const Fixed&src){
	this->_number = this->_number * src.getRawBits();
	this->_number /= 256.0;
	return *this;
}

Fixed Fixed::operator*(const Fixed&src){
	Fixed temp = *this;
	temp *= src;
	return temp;
}

Fixed &Fixed::operator/=(const Fixed&src){
	this->_number = this->_number / src.getRawBits();
	return *this;
}

Fixed Fixed::operator/(const Fixed&src){
	Fixed temp = *this;
	temp /= src;
	return temp;
}

bool Fixed::operator<(const Fixed&src){
	if (this->_number < src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(const Fixed&src){
	if (this->_number > src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed&src){
	if (this->_number <= src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed&src){
	if (this->_number >= src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed&src){
	if (this->_number == src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed&src){
	if (this->_number != src.getRawBits())
		return true;
	return false;
}

Fixed &Fixed::min(const Fixed&src, const Fixed&src2){
	static Fixed result;
	if (src.getRawBits() < src2.getRawBits())
	{
		result = src;
		return result;
	}
	result = src2;
	return result;
}

Fixed &Fixed::max(const Fixed&src, const Fixed&src2){
	static Fixed result;
	if (src.getRawBits() > src2.getRawBits())
	{
		result = src;
		return result;
	}
	result = src2;
	return result;
}

Fixed &Fixed::min(Fixed&src, Fixed&src2){
	if (src.getRawBits() < src2.getRawBits())
		return src;
	return src2;
}

Fixed &Fixed::max(Fixed&src, Fixed&src2){
	if (src.getRawBits() > src2.getRawBits())
		return src;
	return src2;
}