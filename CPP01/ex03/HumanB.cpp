#include "HumanB.hpp"

HumanB::HumanB(const std::string &humanName)
: name(humanName), weapon(NULL)
{}

HumanB::~HumanB()
{ delete weapon; }

void	HumanB::setWeapon(Weapon &zeWeapon)
{
	if (weapon)
		delete weapon;
	weapon = new Weapon(zeWeapon);
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << "is disarmed!" << std::endl;
}
