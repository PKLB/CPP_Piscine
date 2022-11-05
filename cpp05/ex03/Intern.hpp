#pragma once
#include <iostream>
#include "Form.hpp"
using std::string;

class Form;

class	Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern& src);

		Form	*makeForm(string formName, string targetForm);

		class WrongName : public std::exception{
			virtual const char* what() const throw(){
				return("This form does not exist !");
			}
		};
};