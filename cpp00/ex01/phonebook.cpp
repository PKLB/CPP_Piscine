#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <termios.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"
using std::string;

void	typeWriter(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		usleep(15000);
		std::cout << str[i] << std::flush;
	}
}

void	addContact(PhoneBook *book)
{
	static int n;
	string str;

	if (n == 8)
		n = 0;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			while (1)
			{
				typeWriter("\033[1;32m------------------------------------\nPlease enter the firstname!\n------------------------------------\033[0m\n");
				getline(std::cin, str);
				if (std::cin.eof() == 1)
					exit(1);
				if (str.length() > 0)
				{
					book->cont[n].modifyFirstName(str);
					str = "\033[1;32m------------------------------------\n" + str + " has been added to the contact list.\n\033[0m";
					typeWriter(str);
					break ;
				}
			}
		}
		if (i == 1)
		{
			while (1)
			{
				typeWriter("\033[1;32mNow, could you enter the lastname?\n------------------------------------\033[0m\n");
				getline(std::cin, str);
				if (std::cin.eof() == 1)
					exit(1);
				if (str.length() > 0)
				{
					book->cont[n].modifyLastName(str);
					typeWriter("\033[1;32m------------------------------------\nOk perfect !\033[0m");
					break ;
				}
			}
		}
		if (i == 2)
		{
			while (1)
			{
				typeWriter("\033[1;32m Please enter the nickname\n\033[1;32m------------------------------------\033[0m\n");
				getline(std::cin, str);
				if (std::cin.eof() == 1)
					exit(1);
				if (str.length() > 0)
				{
					book->cont[n].modifyNickname(str);
					typeWriter("\033[1;32m------------------------------------\nThanks!\033[0m");
					break ;
				}
			}
		}
		if (i == 3)
		{
			while (1)
			{
				typeWriter("\033[1;32m Please enter the phone number.\n\033[1;32m------------------------------------\033[0m\n");
				getline(std::cin, str);
				if (std::cin.eof() == 1)
					exit(1);
				if (str.length() > 0)
				{
					book->cont[n].modifyPhoneNumber(str);
					typeWriter("\033[1;32m------------------------------------\nThanks!\033[0m");
					break ;
				}
			}
		}
		if (i == 4)
		{
			while (1)
			{
				typeWriter("\033[1;32m And to finish....please enter the contact's darkest secret!\n\033[1;32m------------------------------------\033[0m\n");
				getline(std::cin, str);
				if (std::cin.eof() == 1)
					exit(1);
				if (str.length() > 0)
				{
					book->cont[n].modifyDarkestSecret(str);
					typeWriter("\033[1;32m------------------------------------\nWe're all good, thank you.\n\033[1;32m------------------------------------\033[0m\n");
					break ;
				}
			}
		}
	}
	n++;
	return ;
}

void	displayInfo(PhoneBook *book, string str)
{
	if (str.length() > 9)
		std::cout << std::setw(9) << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str.substr(0, 10) << "|";
}

void	checkInfo(PhoneBook *book, int i)
{
	std::cout << "\033[1;36m|\033[1;33m[" << i << ']' << "\033[1;36m|";
	displayInfo(book, book->cont[i].getFirstName());
	displayInfo(book, book->cont[i].getLastName());
	displayInfo(book, book->cont[i].getNickname());
	displayInfo(book, book->cont[i].getPhoneNumber());
	std::cout << "\033[0m\n";
}

int	showContact(PhoneBook *book, int nb)
{
	if (book->cont[nb].getFirstName().length() < 1)
	{
		typeWriter("\033[1;31mThis contact is not registered yet, try another one.\033[0m\n");
		return (1);
	}
	typeWriter("\033[1;36m------------------------------------\n");
	std::cout << "📕 " << book->cont[nb].getFirstName() << std::endl;
	std::cout << "📗 " << book->cont[nb].getLastName() << std::endl;
	std::cout << "📘 " << book->cont[nb].getNickname() << std::endl;
	std::cout << "📱 " << book->cont[nb].getPhoneNumber() << std::endl;
	std::cout << "💀 " << book->cont[nb].getDarkestSecret() << std::endl;
	std::cout << "\033[1;36m------------------------------------\n\033[0m";
	return (0);
}

int	displayContact(PhoneBook *book, char nb)
{
	switch (nb)
	{
		case ('0'):
			return showContact(book, 0);
		case ('1'):
			return showContact(book, 1);
		case ('2'):
			return showContact(book, 2);
		case ('3'):
			return showContact(book, 3);
		case ('4'):
			return showContact(book, 4);
		case ('5'):
			return showContact(book, 5);
		case ('6'):
			return showContact(book, 6);
		case ('7'):
			return showContact(book, 7);
	}
	typeWriter("\033[1;31mThis index does not exist.\033[0m\n");
	return (0);
}

void	searchContact(PhoneBook *book)
{
	string str;
	typeWriter("\033[1;36m-------------------------------------------------\n");
	for (int i = 0; i < 8; i++)
			checkInfo(book, i);
	std::cout << "\033[1;36m-------------------------------------------------\n";
	typeWriter("\033[1;34mPlease enter the index of the contact you want to display\033[0m\n");
	getline(std::cin, str);
	if (str.length() > 1)
		displayContact(book, '8');
	else
		displayContact(book, str[0]);
	return ;
}

int	main()
{
	string str;
	PhoneBook book;
	while (1)
	{
		str = "\033[1;32m[ADD] - \033[1;36m[SEARCH] - \033[1;31m[EXIT]\033[0m\n";
		typeWriter(str);
		getline(std::cin, str);
		if (std::cin.eof() == 1)
			return (-1);
		if (str == "ADD")
			addContact(&book);
		if (str == "SEARCH")
			searchContact(&book);
		if (str == "EXIT")
		{
			typeWriter("\033[1;31mShutting down the phonebook... your contact(s) will be lost forever ❗️\033[0m\n");
			break ;
		}
	}
	return (0);
}
