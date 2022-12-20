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
		void	beSigned(const Bureaucrat& src);

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

	private:
		bool			_isSigned;
		const int		_execGrade;
		const int		_signGrade;
		const 	string 	_name;
};

std::ostream& operator<<(std::ostream& os, const Form& src);
