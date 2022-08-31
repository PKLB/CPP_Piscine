#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
using std::string;

int main()
{
	{
		Weapon club = Weapon("1");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("2");
		//std::cout << club.getType() << std::endl;
		bob.attack();
	}
	{
		Weapon club = Weapon("1");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("2");
		jim.attack();
	}
}

/*Now, create two classes: HumanA and HumanB. They both have a Weapon and a
name. They also have a member function attack() that displays (of course, without the
angle brackets):
<name> attacks with their <weapon type>
HumanA and HumanB are almost the same except for these two tiny details:
• While HumanA takes the Weapon in its constructor, HumanB doesn’t.
• HumanB may not always have a Weapon, whereas HumanA will always be armed.*/