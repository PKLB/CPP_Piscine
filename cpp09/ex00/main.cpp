#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

void read_map(std::map<std::string, std::string> input)
{
	std::map<std::string, std::string>::iterator itr;
	for (itr = input.begin(); itr != input.end(); itr++)
		std::cout << "\033[1;36m" << itr->first << " \033[1;32m" << itr->second << "\033[0m\n";
	std::cout << input.size() << std::endl;
}

std::map<std::string, std::string> get_data(std::string text, char sep)
{
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

// void check_date(std::string stringo)
// {
	
// }

void check_data(std::string text, std::map<std::string, std::string> data)
{
	std::string line;
	std::ifstream input(text);
	while (getline(input, line))
	{
		std::stringstream ss(line);
		std::string key, value;

		getline(ss, key, ' ');
		getline(ss, value);
		std::map<std::string, std::string>::iterator itr = data.find(key);
		if (value.length() == 0)
			continue ;
		if (itr != data.lower_bound(key))
		{
			itr = data.lower_bound(key);
			itr--;
		}
		if(itr == data.end())
			continue ;
		value = value.substr(2, value.length());
		double new_value = stod(value);
		// if (check_date(key) != 0)
		// {
		// 	std::cout << "Error: bad input =>" << key << std::endl;
		// 	continue ;
		// }
		if (new_value > 999)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		if (new_value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		double second_new_value = stod(itr->second);
		double result = new_value * second_new_value;
		std::cout << key << " => " << value << " = " << result << std::endl;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		std::string input_txt(argv[1]);
		std::map<std::string, std::string> data_csv = get_data("data.csv", ',');
		check_data(input_txt, data_csv);
		// read_map(data_csv);
	}
	else
		std::cout << "\033[1;31mError: could not open file." << std::endl; 
}
