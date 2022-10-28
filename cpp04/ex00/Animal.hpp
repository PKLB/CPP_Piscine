#pragma once
#include <string>
#include <iostream>
using std::string;

class Animal
{
	public:
		Animal();
		Animal(const Animal &src);
		~Animal();

		string getType() const;
		void setType(string src);
				
		Animal &operator=(const Animal& src);
		friend std::ostream& operator<<(std::ostream& os, const Animal& src);

		virtual void makeSound() const;
	protected:
		std::string _type;
};




// virtual makeSound()
// {
// 	std::cout << "miou\n";
// };