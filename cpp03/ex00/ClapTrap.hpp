#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string>
using std::string;

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap& src);

		string 	getName() const;
		int		getHitPoints() const;
		int		getEnergyPoints() const;
		int		getAttackDamage() const;
		void	setHitPoints(int nb);
		void	setEnergyPoints(int nb);
		void	setAttackDamage(int nb);

		void 	attack(const std::string& target);
		void 	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
	private:
		string _name;
		int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& src);

#endif