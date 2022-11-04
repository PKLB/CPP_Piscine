#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form(0, 145, 137)
{
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string src): Form(src, 0, 145, 137)
{
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string name, string src): Form(name, src, 0, 145, 137)
{
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):  Form(src.getName(), 0, 145, 137)
{
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

void 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (getSigned() == 0)
			throw(unsignedException());
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException(executor));
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << executor.getName() << " created " << getTarget() << std::endl;
	}
	catch(const string str)
	{
		std::cout << str; 
	}
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& src)
{
	if (src.getSigned() == 0)
		os << src.getName() << " ShrubberyCreationForm isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
	else
		os << src.getName() << " ShrubberyCreationForm is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
    return os;
}
