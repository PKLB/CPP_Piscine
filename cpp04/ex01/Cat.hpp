#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		~Cat();

		Cat &operator=(const Cat& src);
		friend std::ostream& operator<<(std::ostream& os, const Cat& src);
		
		void makeSound() const;
	private:
		Brain *_Brain;
};