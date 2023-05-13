#pragma once
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

class RPN {
	public:
		RPN();
		void calculate_data(std::string input_txt);
		int check_data(std::string input_txt);
		RPN(const RPN& src);
		~RPN();
		RPN& operator=(const RPN& src);
};