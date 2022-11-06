#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): Form(0, 25, 5){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(string src): Form(src, 0, 25, 5){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(string name, string src): Form(name, src, 0, 25, 5){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):  Form(src.getName(), 0, 25, 5){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm has been destroyed" << std::endl;
}

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try
	{
		if (getSigned() == 0)
			throw(GradeTooLowException());
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << getTarget() << " has been forgiven by mister Zaphod Beeblebrox.\n";
	}
	catch (const std::exception &str)
	{
		std::cout << str.what() << std::endl;
	}
}

void 	PresidentialPardonForm::execute(int grade, string name) const{
	try
	{
		if (getSigned() == 0)
			throw(GradeTooLowException());
		if (grade > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << name << " executed " << getName() << std::endl;
		std::cout << getTarget() << " has been forgiven by mister Zaphod Beeblebrox.\n";
	}
	catch (const std::exception &str)
	{
		std::cout << str.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& src){
	if (src.getSigned() == 0)
		os << src.getName() << " PresidentialPardonForm isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
	else
		os << src.getName() << " PresidentialPardonForm is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
    return os;
}
