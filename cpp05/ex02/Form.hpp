#pragma once
#include "Bureaucrat.hpp"

class	Form
{
	public:
		Form();
		Form(string src);
		Form(string target, string src);
		Form(int isSigned, int execGrade, int signGrade);
		Form(string str, int isSigned, int execGrade, int signGrade);
		Form(string target, string str, int isSigned, int execGrade, int signGrade);
		Form(const Form &src);
		virtual ~Form();

		Form &operator=(const Form& src);

		string 			getName() const;
		string 			getTarget() const;
		int 			getExecGrade() const;
		int 			getSignGrade() const;
		int 			getSigned() const;
		void 			setExecGrade(int src);
		void 			setSignGrade(int src);
		void			beSigned(const Bureaucrat& src);
		virtual void 	execute(Bureaucrat const & executor) const = 0;

		string			GradeTooHighException() const;
		string			unsignedException() const;
		string			GradeTooLowException(const Bureaucrat& src) const;

	private:
		bool			_isSigned;
		int				_execGrade;
		int				_signGrade;
		const 	string 	_name;
		const 	string 	_target;
};

std::ostream& operator<<(std::ostream& os, const Form& src);
