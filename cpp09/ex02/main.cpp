#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

// void sort_list()
// {

// }

// void sort_vector()
// {

// }

int check_data(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string print_before;
		std::list<int> listo;
		for (int i = 1; i < argc; i++)
		{
			if (check_data(argv[i]) == 1)
				return 1;
			listo.push_back(atoi(argv[i]));
			// vector += argv[i];
			print_before += argv[i];
			if (i + 1 != argc)
				print_before += " ";
		}
		std::list<int>::iterator it;
		for (it = listo.begin(); it != listo.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;;
		std::cout << "Before: " << print_before << std::endl;
		// sort_vector(vector);
		// sort_list(vector);
	}
	else
		std::cout << "\033[1;31mError: no arguments given." << std::endl;
}
