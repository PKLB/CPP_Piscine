#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(0, 137, 145){
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target): AForm(target, 0, 137, 145){
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string name, string target): AForm(name, target, 0, 137, 145){
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):  AForm(src.getName(), 0, 137, 145){
	std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

void 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	try{
		if (getSigned() == 0)
			throw(NotSignedException());
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		string tmp = getTarget() + "_shrubbery";
		std::ofstream MyFile(tmp);
		MyFile << "   /\\       /\\      /\\       /\\ \n";
		MyFile << "  /  \\     /  \\    /  \\     /  \\ \n";
		MyFile << " /____\\   /____\\  /____\\   /____\\ \n";
		MyFile << "   ||       ||      ||       ||     \n";
		MyFile.close();
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

void 	ShrubberyCreationForm::execute(int grade, string name) const{
	try{
		if (getSigned() == 0)
			throw(NotSignedException());
		if (grade > this->getExecGrade())
			throw(GradeTooLowException());
		std::cout << "\033[1;36m" << name << " executed " << getName() << "\033[0m" << std::endl;
		string tmp = getTarget() + "_shrubbery";
		std::ofstream MyFile(tmp);
		MyFile << "   /\\       /\\      /\\       /\\ \n";
		MyFile << "  /  \\     /  \\    /  \\     /  \\ \n";
		MyFile << " /____\\   /____\\  /____\\   /____\\ \n";
		MyFile << "   ||       ||      ||       ||     \n";
		MyFile.close();
	}
	catch (const std::exception &str){
		std::cout << str.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& src){
	if (src.getSigned() == 0)
		os << "\033[1;34m- " << src.getName() << " ShrubberyCreationForm isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
	else
		os << "\033[1;34m- " << src.getName() << " ShrubberyCreationForm is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
    return os;
}
