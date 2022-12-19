#pragma once
#include <iostream>
using std::string;

class Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(string target);
		AForm(string target, string name);
		AForm(int isSigned, int execGrade, int signGrade);
		AForm(string target, int isSigned, int execGrade, int signGrade);
		AForm(string target, string name, int isSigned, int execGrade, int signGrade);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm &operator=(const AForm& src);

		string 			getName() const;
		string 			getTarget() const;
		int 			getExecGrade() const;
		int 			getSignGrade() const;
		int 			getSigned() const;
		void 			setExecGrade(int src);
		void 			setSignGrade(int src);
		void 			makeItSigned();
		void			beSigned(const Bureaucrat& src);
		virtual void 	execute(const Bureaucrat &executor) const = 0;
		virtual void 	execute(int grade, string name) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw(){
				return("\033[1;31m[Grade too high !]\033[0m");
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw(){
				return("\033[1;31m[Grade too low !]\033[0m");
			}
		};
		class NotSignedException : public std::exception
		{
			virtual const char* what() const throw(){
				return("\033[1;31m[Form isn't signed !]\033[0m");
			}
		};

	private:
		bool			_isSigned;
		int				_execGrade;
		int				_signGrade;
		const 	string 	_name;
		const 	string 	_target;
};

std::ostream& operator<<(std::ostream& os, const AForm& src);
