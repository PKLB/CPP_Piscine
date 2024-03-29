#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){
	(void)src;
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){
	(void)src;
	return *this;
}

void BitcoinExchange::read_map(std::map<std::string, std::string> input){
	std::map<std::string, std::string>::iterator itr;
	for (itr = input.begin(); itr != input.end(); itr++)
		std::cout << "\033[1;36m" << itr->first << " \033[1;32m" << itr->second << "\033[0m\n";
	std::cout << input.size() << std::endl;
}

std::map<std::string, std::string> BitcoinExchange::get_data(std::string text, char sep){
	std::map<std::string, std::string> temp;
	std::ifstream input(text);
	std::string line;
	while (getline(input, line))
	{
		std::stringstream ss(line);
		std::string key, value;
		getline(ss, key, sep);
		getline(ss, value);
		temp.insert(std::pair<std::string,std::string>(key, value));
	}
	return temp;
}

int BitcoinExchange::check_date(std::string stringo)
{
	if (stringo.length() > 10)
		return 1;
	std::string year = stringo.substr(0, 4);
	std::string month = stringo.substr(5, 2);
	std::string day = stringo.substr(8, 2);
	try {
		stod(year), stod(month), stod(day);
	}
	catch(...){
		std::cout << "\033[1;31mError: bad input => " << stringo << "\033[0m" << std::endl;
		return 1;
	}
	int day_int = stod(day);
	int month_int = stod(month);
	if (month_int < 0 || month_int > 12 || day_int < 0 || day_int > 31)
		return 1;
	if (month_int == 2 && day_int > 29)
		return 1;
	return 0;
}

void BitcoinExchange::check_data(std::string text, std::map<std::string, std::string> data){
	std::string line;
	std::ifstream input(text);
	while (getline(input, line)){
		std::stringstream ss(line);
		std::string key, value;

		getline(ss, key, ' ');
		if (key.length() > 0){
			if (key == "date")
				continue;
			if (check_date(key) != 0)
			{
				std::cout << "\033[1;31mError: bad input => " << key << "\033[0m" << std::endl;
				continue ;
			}
		}
		std::map<std::string, std::string>::iterator itr = data.find(key);
		getline(ss, value);
		if (value.length() < 2){
			std::cout << "\033[1;31mError: bad value." << "\033[0m" << std::endl;
			continue ;
		}
		try {
			if (itr != data.lower_bound(key)){
				itr = data.lower_bound(key);
				if (itr != data.begin())
					itr--;
			}
			if(itr == data.end())
				continue ;
			value = value.substr(2, value.length());
		}
		catch(...){
			std::cout << "\033[1;31mError: bad value." << "\033[0m" << std::endl;
			continue ;
		}
		try {
			if (key == "date" && value == "value")
				continue;
			if (stod(value) <= 0)
			{
				std::cout << "\033[1;31mError: bad input => " << value << "\033[0m" << std::endl;
				continue ;
			}
		}
		catch(...){
			std::cout << "\033[1;31mError: bad input => " << value << "\033[0m" << std::endl;
			continue ;
		}
		double new_value = stod(value);
		if (new_value > 999){
			std::cout << "\033[1;31mError: too large a number." << "\033[0m" << std::endl;
			continue ;
		}
		if (new_value < 0){
			std::cout << "\033[1;31mError: not a positive number." << "\033[0m" << std::endl;
			continue ;
		}
		try {
			stod(itr->second);
		}
		catch(...){
			std::cout << "\033[1;31mError: bad input => " << itr->second << "\033[0m" <<std::endl;
			continue;
		}
		double second_new_value = stod(itr->second);
		double result = new_value * second_new_value;
		std::cout << "\033[1;36m" << key << " \033[0m => \033[1;32m" << value << " \033[0m = \033[1;33m" << result << std::endl;
	}
}