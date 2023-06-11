#include "RPN.hpp"

RPN::RPN(){
	
}

RPN::RPN(const RPN& src){
	(void)src;
}

RPN::~RPN(){

}

RPN& RPN::operator=(const RPN& src){
	(void)src;
	return *this;
}


void RPN::calculate_data(std::string input_txt){
	std::stack<int> numbers;
	std::stringstream stream(input_txt);
	std::string tok;
	while (getline(stream, tok, ' '))
	{
		if (isdigit(tok[0]))
			numbers.push(stod(tok));
		else if (numbers.size() >= 2)
		{
			int nb1 = numbers.top();
			numbers.pop();
			int nb2 = numbers.top();
			numbers.pop();
			int result = 0;
			if (tok == "+")
				result = nb2 + nb1;
			if (tok == "/")
			{
				if (nb2 == 0 || nb1 == 0)
				{
					std::cout << "Error: cannot divide by 0" << std::endl;
					return ;
				}	
				result = nb2 / nb1;
			}
			if (tok == "*")
				result = nb2 * nb1;
			if (tok == "-")
				result = nb2 - nb1;
			numbers.push(result);
		}
	}
	if (numbers.size() > 1)
	{
		std::cout << "error" << std::endl;
		return ;
	}
	while (!numbers.empty())
	{
		if (numbers.size() > 1)
			std::cout << numbers.top() << " ";
		else
			std::cout << numbers.top() << std::endl;
		numbers.pop();
	}
}

int RPN::check_data(std::string input_txt){
	std::stringstream stream(input_txt);
	std::string tok;
	while (getline(stream, tok, ' '))
	{
		if (tok.length() > 1)
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
		if (isdigit(tok[0]))
		{
			if (stod(tok) > 10 || stod(tok) < 0)
				std::cout << "Error" << std::endl;
		}
		else if (tok != "-" && tok != "+" && tok != "/" && tok != "*")
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	return 0;
}