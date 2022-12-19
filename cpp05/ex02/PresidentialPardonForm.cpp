#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(0, 5, 25){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(string src): AForm(src, 0, 5, 25){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(string name, string src): AForm(name, src, 0, 5, 25){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):  AForm(src.getName(), 0, 5, 25){
	std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm has been destroyed" << std::endl;
}

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try{
		if (getSigned() == 0)
			throw(NotSignedException());
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << getTarget() << " has been forgiven by mister Zaphod Beeblebrox.\n";
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

void 	PresidentialPardonForm::execute(int grade, string name) const{
	try{
		if (getSigned() == 0)
			throw(NotSignedException());
		if (grade > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << "\033[1;36m" << name << " executed " << getName() << "\033[0m" << std::endl;
		std::cout << getTarget() << " has been forgiven by mister Zaphod Beeblebrox.\n";
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& src){
	if (src.getSigned() == 0)
		os << "\033[1;34m- " << src.getName() << " PresidentialPardonForm isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
	else
		os << "\033[1;34m- " << src.getName() << " PresidentialPardonForm is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
    return os;
}
