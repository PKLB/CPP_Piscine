#pragma once
#include <string>
#include <iostream>
using std::string;

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(string src);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal();

		string getType() const;
		void setType(string src);
				
		WrongAnimal &operator=(const WrongAnimal& src);

		virtual void makeSound() const;
	protected:
		std::string _type;
};

 std::ostream& operator<<(std::ostream& os, const WrongAnimal& src);
