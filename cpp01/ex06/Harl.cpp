#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"
using std::string;

Harl::Harl()
{
}

Harl::~Harl()
{

}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void Harl::info( void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger ! If you did, I wouldn't be asking for more !\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been comingfor years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

void Harl::complain(string level)
{
	enum level_int {DEBUG = 1, INFO, WARNING, ERROR};
	int blabla = (level == "WARNING") ? WARNING : \
	(level == "INFO") ? INFO : \
	(level == "ERROR") ? ERROR : \
	(level == "DEBUG") ? DEBUG : \
	10;

	switch (blabla)
	{
		case 1:
			std::cout << "[ DEBUG ]\n";
			warning();
		case 2:
			std::cout << "[ INFO ]\n";
			info();
		case 3:
			std::cout << "[ WARNING ]\n";
			error();
		case 4:
			std::cout << "[ ERROR ]\n";
			return debug();
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
