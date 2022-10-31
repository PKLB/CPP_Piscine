#include <string>
#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	this->_Ideas = new string [100];
	std::cout << "Brain constructor called \n";	
}
                                                                                  
Brain::~Brain()
{
	delete[] _Ideas;
	std::cout << "Brain destructor called \n";
}

Brain::Brain(const Brain &src)
{
	delete[] _Ideas;
	this->_Ideas = src._Ideas;
}

Brain &Brain::operator=(const Brain& src)
{
	this->_Ideas = src._Ideas;
	std::cout << "Copy assignement operator called\n";
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Brain& src)
{
	for (int i = 0; i < 100; i++)
		os << src._Ideas[i] << std::endl;
    return os;
}

string	*Brain::getIdeas() const
{
	return(_Ideas);
}

void	Brain::setIdeas(string src)
{
}
