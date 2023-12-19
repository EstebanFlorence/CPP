#include "HumanA.hpp"

HumanA::HumanA(const std::string& humanName, Weapon& Weapon)
: name(humanName), weapon(Weapon)
{}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
