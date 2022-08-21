#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <string>
using std::string;

class   Zombie
{
    public:
		Zombie();
        void	announce( void );
        Zombie*	newZombie( std::string name );
        void	randomChump( std::string name );
		~Zombie();
    private:
        string 	name;
};

#endif