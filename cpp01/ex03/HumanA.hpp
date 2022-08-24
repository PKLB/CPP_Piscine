#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <iostream>
#include <string>
using std::string;

class   HumanA
{
    public:
		HumanA();
		const string& getType();
		const string setType(string str);
		~HumanA();
    private:
        string 	type;
};

#endif