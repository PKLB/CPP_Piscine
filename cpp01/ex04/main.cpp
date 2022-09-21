#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::string;

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		string filename = argv[1];
		string filenameReplace = filename + ".replace";
		string s1 = argv[2];
		string s2 = argv[3];
		std::ifstream infile(filename);
		std::stringstream tmp;
		tmp << infile.rdbuf();
		string tmp2 = tmp.str();
	}
}
