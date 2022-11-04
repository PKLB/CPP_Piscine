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
		void 	setExecGrade(int src);
		void 	setSignGrade(int src);

		void	beSigned(const Bureaucrat src);
		string	GradeTooHighException() const;
		string	GradeTooLowException() const;

	private:
		bool			_isSigned;
		int				_ExecGrade;
		int				_SignGrade;
		const 	string 	_name;
};

std::ostream& operator<<(std::ostream& os, const Form& src);
