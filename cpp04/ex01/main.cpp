#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main ()
{
	const Animal *tab[10];
	for (int i = 0; i < 5; i++)
		tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat();

	std::cout << tab[5]->getType() << std::endl;
	
	for (int i = 0; i < 10; i++)
		delete tab[i];

	return (0);
}