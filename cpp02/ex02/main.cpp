#include "Fixed.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	// if (a > b){
	// 	std::cout << a << " > " << b << std::endl;
	// 	std::cout << "a is superior to b" << std::endl;
	// }
	// if (a < b == true)
	// 	std::cout << "a is inferior to b" << std::endl;
	// if (a != b)
	// 	std::cout << "a is different of b" << std::endl;
	// if (a == b)
	// 	std::cout << "a is equal to b" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}