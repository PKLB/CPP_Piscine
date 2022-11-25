#include <iostream>
#include <string>
#include "iter.hpp"

int testo(int i)
{		
	std::cout << "Before: " << i << std::endl << "After: " << i * 2 << std::endl;
	return i * 2;
}

int main ()
{
	int tab[5] = {1, 2, 3, 4, 5};
	::iter(tab, 5, &testo);
	return 0;
}