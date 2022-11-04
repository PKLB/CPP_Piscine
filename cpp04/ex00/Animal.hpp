#pragma once
#include <string>
#include <iostream>
using std::string;

class Animal
{
	public:
		Animal();
		Animal(string src);
		Animal(const Animal &src);
		virtual ~Animal();

		string getType() const;
		void setType(string src);
				
		Animal &operator=(const Animal& src);

		virtual void makeSound() const;
	protected:
		std::string _type;
};

std::ostream& operator<<(std::ostream& os, const Animal& src);
