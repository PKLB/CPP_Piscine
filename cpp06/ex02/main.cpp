#include <iostream>
#include <time.h>
#include "Base.hpp"

Base* generate(void){
	srand (time(NULL));
	int i = rand() % 3 + 1;
	if (i == 1)
	{
		Base *toto = new A;
		std::cout << "A created !" << std::endl;
		return (toto);
	}
	if (i == 2)
	{
		Base *toto = new B;
		std::cout << "B created !" << std::endl;
		return (toto);
	}
	Base *toto = new C;
	std::cout << "C created !" << std::endl;
	return (toto);
}

void identify(Base* p){
	A *toto = dynamic_cast<A*>(p);
	B *momo = dynamic_cast<B*>(p);
	C *bobo = dynamic_cast<C*>(p);
	if (toto != NULL)
		std::cout << "I'm A!" << std::endl;
	if (momo != NULL)
		std::cout << "I'm B!" << std::endl;
	if (bobo != NULL)
		std::cout << "I'm C!" << std::endl;
	return ;
}

void identify(Base& p){
	try{
		A toto = dynamic_cast<A&>(p);
	}
	catch(std::exception){
		try{
			B momo = dynamic_cast<B&>(p);
		}
		catch(std::exception){
			std::cout << "Yes, I'm C!" << std::endl;
			return ;
		}
	}
	try{
		B toto = dynamic_cast<B&>(p);
	}
	catch(std::exception){
		try{
			C momo = dynamic_cast<C&>(p);
		}
		catch(std::exception){
			std::cout << "Yes, I'm A!" << std::endl;
			return ;
		}
	}
	std::cout << "Yes, I'm B!" << std::endl;
	return ;
}

int main(void)
{
	Base* toto = generate();
	identify(toto);
	identify(*toto);
	delete toto;
	return 0;
}