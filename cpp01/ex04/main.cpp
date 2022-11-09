#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstring>
using std::string;

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		string filename = argv[1];
		string filenameReplace = filename + ".replace";
		char *s1= argv[2];
		string s2 = argv[3];
		std::ifstream infile(filename);
		std::stringstream tmp;
		tmp << infile.rdbuf();
		string tmp2 = tmp.str();
		int n = tmp2.length();
		char stringos[n + 1];
		std::strcpy(stringos, tmp2.c_str());
		//tmp2 = tmp2.split(s1).join(s2);

		char *str;
		string tab;
		std::cout << stringos;
		str = strtok(stringos, s1);
		while (str != NULL)
		{
			tab += str;
			tab += s2;
			std::cout << tab;
			str = strtok(stringos, s1);
		}

	}
}
