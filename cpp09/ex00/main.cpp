#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "BitcoinExchange.hpp"

int main (int argc, char **argv){
	
	if (argc == 2)
	{
		BitcoinExchange yoyoyooo;
		std::string input_txt(argv[1]);
		try{
			std::map<std::string, std::string> data_csv = yoyoyooo.get_data("data.csv", ',');
			yoyoyooo.check_data(input_txt, data_csv);
			// yoyoyooo.read_map(data_csv);
		}
		catch(...){
			std::cout << "Bad input" << std::endl;
		}
	}
	else
		std::cout << "\033[1;31mError: could not open file.\033[0m" << std::endl; 
}
