#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc == 2)
	{
		RPN yoyoyoyoupiyoyoupiyeah;
		std::string input_txt(argv[1]);
		if (yoyoyoyoupiyoyoupiyeah.check_data(input_txt) == 1)
			return 0;
		yoyoyoyoupiyoyoupiyeah.calculate_data(input_txt);
	}
	else
		std::cout << "\033[1;31mError: one argument only." << std::endl;
}
