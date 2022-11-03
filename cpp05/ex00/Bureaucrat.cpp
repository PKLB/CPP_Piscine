#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}
			
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
}
			
Bureaucrat::~Bureaucrat()
{
}
			
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src)
{
	return *this;
}
			
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}
			
void Bureaucrat::setGrade(int src)
{
	this->_grade = src;
}
			