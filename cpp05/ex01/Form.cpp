#include "Form.hpp"


Form::Form(): _name("PNJ")
{
	std::cout << "Form has been created" << std::endl;
}

Form::Form(string src): _name(src)
{
	std::cout << "Form has been created" << std::endl;
}

Form::Form(const Form &src): _name(src._name)
{
	this->_grade = src._grade; 
	std::cout << "Form has been created" << std::endl;
}

Form::~Form()
{
	std::cout << "Form has been destroyed" << std::endl;
}

Form &Form::operator=(const Form& src)
{
	this->_grade = src._grade; 
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& src)
{
	os << src.getName() << ", Form grade " << src.getGrade() << std::endl;
    return os;
}

string Form::getName() const
{
	return (this->_name);
}

int Form::getGrade() const
{
	return (this->_grade);
}

void Form::setGrade(int src)
{
	this->_grade = src;
}

void	Form::upGrade()
{
	try
	{
		if (this->_grade - 1 < 1)
			throw(GradeTooHighException());
		this->_grade--;
	}
	catch (const string str)
	{
		std::cout << str << std::endl;
	}
}

void	Form::downGrade()
{
	try
	{
		if (this->_grade + 1 > 150)
			throw(GradeTooLowException());
		this->_grade++;
	}
	catch (const string str)
	{
		std::cout << str << std::endl;
	}
}

string	Form::GradeTooHighException() const
{
	return ("Grade too high!");
}

string	Form::GradeTooLowException() const
{
	return ("Grade too low!");
}

