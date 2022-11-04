#include "Bureaucrat.hpp"

class	Form
{
	public:
		Form();
		Form(string src);
		Form(const Form &src);
		~Form();

		Form &operator=(const Form& src);

		string 	getName() const;
		int 	getExecGrade() const;
		int 	getSignGrade() const;
		int 	getSigned() const;
		void 	setExecGrade(int src);
		void 	setSignGrade(int src);
		void	beSigned(const Bureaucrat& src);


		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw(){
				return("Grade too high !");
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw(){
				return("Grade too low !");
			}
		};

	private:
		bool			_isSigned;
		int				_execGrade;
		int				_signGrade;
		const 	string 	_name;
};

std::ostream& operator<<(std::ostream& os, const Form& src);
