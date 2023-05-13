#pragma once
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

class BitcoinExchange {
	public:
		BitcoinExchange();
		void read_map(std::map<std::string, std::string> input);
		std::map<std::string, std::string> get_data(std::string text, char sep);
		void check_data(std::string text, std::map<std::string, std::string> data);
		// void check_date(std::string stringo);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& src);
};
