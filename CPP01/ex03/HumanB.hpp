#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;

	public:
		HumanA::HumanA(std::string);
		HumanA::~HumanA();

		void	setWeapon(Weapon weapon);
		void	attack();
};


#endif