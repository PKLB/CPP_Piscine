#include <iostream>
#include <string>
#include "Contact.hpp"
using std::string;

string Contact::getFirstName(){
	return (_FirstName);
}

string Contact::getLastName(){
	return (_LastName);
}

string Contact::getNickname(){
	return (_Nickname);
}

string Contact::getPhoneNumber(){
	return (_PhoneNumber);
}

string Contact::getDarkestSecret(){
	return (_DarkestSecret);
}

void Contact::modifyFirstName(const string str){
	_FirstName = str;
}

void Contact::modifyLastName(const string str){
	_LastName = str;
}

void Contact::modifyNickname(const string str){
	_Nickname = str;
}

void Contact::modifyDarkestSecret(const string str){
	_DarkestSecret = str;
}

void Contact::modifyPhoneNumber(const string str){
	_PhoneNumber = str;
}
