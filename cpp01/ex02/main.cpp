#include <iostream>
#include <string>
using std::string;

int main()
{
	string str = "HI THIS IS BRAIN\n";
	string *stringPTR = &str;
	string &stringREF = str;

	std::cout << "Address of STR : \033[1;33m" << &str << "\033[0m\n";
	std::cout << "Address of stringPTR : \033[1;33m" << stringPTR << "\033[0m\n";
	std::cout << "Address of stringREF : \033[1;33m" << &stringREF << "\033[0m\n\n";

	std::cout << "Value of STR: \033[1;36m" << str << "\033[0m";
	std::cout << "Value of stringPTR: \033[1;36m" << (*stringPTR) << "\033[0m";
	std::cout << "Value of stringREF: \033[1;36m" << stringREF << "\033[0m";

    return (0);
}