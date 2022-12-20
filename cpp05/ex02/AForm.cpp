#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _isSigned(0), _execGrade(0), _signGrade(0), _name("Random papers"){
	std::cout << "AForm has been created" << std::endl;
}

AForm::AForm(string target, string name): _isSigned(0), _execGrade(0), _signGrade(0), _name(name), _target(target){
	std::cout << "AForm has been created" << std::endl;
}

AForm::AForm(int isSigned, int execGrade, int signGrade): _isSigned(isSigned), _execGrade(execGrade), _signGrade(signGrade), _name("Random papers"), _target("Random target"){
	std::cout << "AForm has been created" << std::endl;
}

AForm::AForm(string target, int isSigned, int execGrade, int signGrade): _isSigned(isSigned), _execGrade(execGrade), _signGrade(signGrade), _name("Random papers"), _target(target){
	std::cout << "AForm has been created" << std::endl;
}

AForm::AForm(string target, string name, int isSigned, int execGrade, int signGrade): _isSigned(isSigned), _execGrade(execGrade), _signGrade(signGrade), _name(name), _target(target){
	std::cout << "AForm has been created" << std::endl;
}

AForm::AForm(const AForm &src): _isSigned(src.getSigned()), _execGrade(src._execGrade), _signGrade(src._signGrade), _name(src._name), _target(src._target){
	std::cout << "AForm has been created" << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm has been destroyed" << std::endl;
}

AForm &AForm::operator=(const AForm&){
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& src){
	if (src.getSigned() == 0)
		os << "\033[1;34m- " << src.getName() << " form isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
	else
		os << "\033[1;34m- " << src.getName() << " form is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << " -\033[0m" << std::endl;
    return os;
}

string AForm::getName() const{
	return (this->_name);
}

int AForm::getSigned() const{
	return (this->_isSigned);
}

int AForm::getExecGrade() const{
	return (this->_execGrade);
}

int AForm::getSignGrade() const{
	return (this->_signGrade);
}

string AForm::getTarget() const{
	return (this->_target);
}

void AForm::makeItSigned(){
	this->_isSigned = 1;
}

void	AForm::beSigned(const Bureaucrat& src){
	try{
		if (src.getGrade() > this->_signGrade)
			throw AForm::GradeTooLowException();
		this->_isSigned = 1;
		src.signForm(this->_name, 0);
	}
	catch (const std::exception &str){
		src.signForm(this->_name, 1);
		std::cout << str.what() << std::endl;
	}
}

