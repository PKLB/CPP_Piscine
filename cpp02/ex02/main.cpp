#include "Fixed.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c = a;
	if (a > c == true)
		std::cout << "a is superior to c" << std::endl;
	if (a < c == true)
		std::cout << "a is superior to c" << std::endl;
	if (a == c)
		std::cout << "a is equal to c" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}

/*
Add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, == and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, that will increase or decrease the fixed-point value from
the smallest representable ϵ such as 1 + ϵ > 1.

Add these four public overloaded member functions to your class:
• A static member function min that takes as parameters two references on fixed-point
numbers, and returns a reference to the smallest one.
• A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.
• A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.
• A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.*/
