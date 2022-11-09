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
		string document = argv[1];
		string outdocument = document + ".replace";
		string s1 = argv[2];
		string s2 = argv[3];

		std::ifstream infile(document, std::ios::binary);
		std::ofstream outfile(outdocument, std::ios::binary);

		string word;
		string result;
		while (getline(infile, word))
			result += word;
		std::cout << result << std::endl;
		int	s1_length = s1.length();
		for (int index = 0; index < result.length(); index++)
		{
			if (result.compare(index, s1_length, s1) == 0)
			{
				result.erase(index, s1_length);
				result.insert(index, s2);
			}
		}
		std::cout << result << std::endl;
		outfile << result;
   		outfile.close();
	}
}
