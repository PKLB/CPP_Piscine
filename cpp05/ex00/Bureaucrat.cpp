#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("PNJ")
{
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(string src): _name(src)
{
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name)
{
	this->_grade = src._grade; 
	std::cout << "Bureaucrat has been created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat has been destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src)
{
	this->_grade = src._grade; 
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return os;
}

string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int src)
{
	this->_grade = src;
}
