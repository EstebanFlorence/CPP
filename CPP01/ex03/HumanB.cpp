#include "HumanB.hpp"

HumanB::HumanB(const std::string& humanName)
: name(humanName), weapon(NULL)
{}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& zeWeapon)
{ weapon = &zeWeapon; }

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " is disarmed!" << std::endl;
}
