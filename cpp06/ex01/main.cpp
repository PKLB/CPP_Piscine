#include <iostream>
#include <string>
#include "Data.hpp"

int main ()
{
	Data test;
	Data toto;
	uintptr_t nb;
	std::cout << &toto << std::endl;
	nb = toto.serialize(&test);
	std::cout << nb << std::endl;
	std::cout << toto.deserialize(nb) << std::endl;
	return 0;
}