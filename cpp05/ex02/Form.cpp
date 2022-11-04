#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Random papers"), _isSigned(0), _execGrade(0), _signGrade(0){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(string src): _target(src), _isSigned(0), _execGrade(0), _signGrade(0){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(string target, string src): _target(target), _name(src), _isSigned(0), _execGrade(0), _signGrade(0){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(int isSigned, int execGrade, int signGrade): _name ("Default"), _isSigned(isSigned), _execGrade(execGrade), _signGrade(signGrade){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(string str, int isSigned, int execGrade, int signGrade): _name ("Default"), _target (str), _isSigned(isSigned), _execGrade(execGrade), _signGrade(signGrade){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(string target, string str, int isSigned, int execGrade, int signGrade): _target(target), _name (str), _isSigned(isSigned), _execGrade(execGrade), _signGrade(signGrade){
	std::cout << "Form has been created" << std::endl;
}

Form::Form(const Form &src): _target(src._target), _name(src._name), _isSigned(src.getSigned()), _execGrade(src._execGrade), _signGrade(src._signGrade){
	std::cout << "Form has been created7" << std::endl;
}

Form::~Form(){
	std::cout << "Form has been destroyed" << std::endl;
}

Form &Form::operator=(const Form& src){
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& src){
	if (src.getSigned() == 0)
		os << src.getName() << " form isn't signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
	else
		os << src.getName() << " form is signed. You must have a grade of " << src.getSignGrade() 
			<< " to sign the form and a grade of " << src.getExecGrade() << " to execute the form" << std::endl;
    return os;
}

string Form::getName() const{
	return (this->_name);
}

int Form::getSigned() const{
	return (this->_isSigned);
}

int Form::getExecGrade() const{
	return (this->_execGrade);
}

int Form::getSignGrade() const{
	return (this->_signGrade);
}

string Form::getTarget() const{
	return (this->_target);
}

void Form::setExecGrade(int src){
	this->_execGrade = src;
}

void Form::setSignGrade(int src)
{
	this->_signGrade = src;
}
