#include <iostream>
#include <string>
#include "MyData.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	if (argc == 2){
		char  *src = argv[1];
		MyData toto(src);
	}
	return 0;
}
