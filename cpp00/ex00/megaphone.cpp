#include <iostream>
#include <string>
using std::string;

int main(int argc, char **argv)
{
	if (argc == 1)
		return (!(std::cout << "\033[1;31m*📣 LOUD AND UNBEARABLE FEEDBACK NOISE 📣*\n"));
	for (int i = 1; i != argc; i++)
	{
		string str = argv[i];
		transform(str.begin(),str.end(), str.begin(), toupper);
		std::cout << str;
	}
	std::cout << std::endl;
}