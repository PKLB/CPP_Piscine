#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main ()
{
	// Animal test;
	// test = Animal("Corbeau");
	// std::cout << test;ß
	// Cat MonsieurLeChat;
	// std::cout << MonsieurLeChat;
	// Dog	Snoop;
	// std::cout << Snoop;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	return (0);
}