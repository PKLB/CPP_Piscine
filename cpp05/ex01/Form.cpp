#include "Form.hpp"

Form::Form(): _name("Random papers"), _isSigned(0)
{
	std::cout << "Form has been created" << std::endl;
}

Form::Form(string src): _name(src), _isSigned(0)
{
	std::cout << "Form has been created" << std::endl;
}

Form::Form(const Form &src): _name(src._name), _isSigned(src.getSigned()), _execGrade(src._execGrade), _signGrade(src._signGrade)
{
	std::cout << "Form has been created" << std::endl;
}

Form::~Form()
{
	std::cout << "Form has been destroyed" << std::endl;
}

Form &Form::operator=(const Form& src)
{
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& src)
{
	if (src.getSigned() == 0)
		os << src.getName() << " form isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
	else
		os << src.getName() << " form is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
    return os;
}

string Form::getName() const
{
	return (this->_name);
}

int Form::getSigned() const
{
	return (this->_isSigned);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

void Form::setExecGrade(int src)
{
	this->_execGrade = src;
}

void Form::setSignGrade(int src)
{
	this->_signGrade = src;
}

void	Form::beSigned(const Bureaucrat& src)
{
	try
	{
		if (src.getGrade() > this->_signGrade)
			throw(Form::GradeTooLowException(src));
		this->_isSigned = 1;
		src.signForm(this->_name, 0);
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

string	Form::GradeTooLowException(const Bureaucrat& src) const
{
	src.signForm(this->_name, 1);
	return ("Grade too low!");
}
