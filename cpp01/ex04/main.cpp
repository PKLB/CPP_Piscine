#include <iostream>
#include <fstream>
#include <string>
using std::string;

// int main(int argc, char *argv[])
// {
// 	if (argc == 4)
// 	{
// 		string document = argv[1];
// 		string outdocument = document + ".replace";
// 		string s1 = argv[2];
// 		string s2 = argv[3];

// 		std::ifstream infile(document);
// 		std::ofstream outfile(outdocument);
// 		if (infile.is_open())
// 		{
// 			std::cout << "We opened the document " << argv[1] << std::endl;
// 			std::string buffer;
// 			while (infile >> buffer)
// 			{
// 				if (s1 == buffer)
// 				{
// 					outfile << s2;
// 					std::cout << "found matching words\n";
// 				}
// 				else
// 					outfile << buffer;
// 			}
// 		}
// 	}
// }

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
		string sentence;
		while (getline(infile, word))
			sentence += word;
		std::cout << sentence << std::endl;
	}
}
