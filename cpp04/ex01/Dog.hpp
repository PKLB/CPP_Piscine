#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& src);
		~Dog();

		Dog &operator=(const Dog& src);
		friend std::ostream& operator<<(std::ostream& os, const Dog& src);

		void makeSound() const;
	private:
		Brain *_Brain;
};