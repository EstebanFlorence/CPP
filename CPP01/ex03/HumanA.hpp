#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;

	public:
		HumanA::HumanA(std::string);
		HumanA::~HumanA();

		void	attack();

};

#endif