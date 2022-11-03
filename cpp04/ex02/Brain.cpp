#include <string>
#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called \n";	
}
                                                                                  
Brain::~Brain()
{
	std::cout << "Brain destructor called \n";
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_Ideas[i] = src._Ideas[i];
}

Brain &Brain::operator=(const Brain& src)
{
	for (int i = 0; i < 100; i++)
		this->_Ideas[i] = src._Ideas[i];
	std::cout << "Copy assignement operator called\n";
	return *this;
}
