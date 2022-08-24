#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
#include <string>
using std::string;

class   Weapon
{
    public:
		Weapon();
		const string& getType();
		const string setType(string str);
		~Weapon();
    private:
        string 	type;
};

#endif