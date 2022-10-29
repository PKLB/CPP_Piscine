#include <string>
#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called \n";	
}

Brain::Brain(string src)
{
	std::cout << "Brain constructor called \n";	
}
                                                                                  
Brain::~Brain()
{
	std::cout << "Brain destructor called \n";
}

Brain::Brain(const Brain &src)
{
}

Brain &Brain::operator=(const Brain& src)
{
	std::cout << "Copy assignement operator called\n";
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Brain& src)
{
    return os;
}

string	Brain::getIdeas() const
{
	return("hello");
}

void	Brain::setIdeas(string src)
{
}
