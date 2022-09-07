#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"
using std::string;

int main(int argc, char **argv)
{
	Harl Karen;
	if (argc == 2)
		Karen.complain(argv[1]);
}
