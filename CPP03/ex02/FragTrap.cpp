#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << ITALIC "FragTrap " << _name << " Default Constructor" CLR_RMV << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << ITALIC "FragTrap " << _name << " Copy Constructor" CLR_RMV << std::endl;
	*this = copy;	
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << ITALIC "FragTrap " << _name << " Parameterized Constructor" CLR_RMV << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << ITALIC "FragTrap " << _name << " Destructor" CLR_RMV << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	FragTrap::highFivesGuys()
{
    std::cout << BOLD "FragTrap " << _name << " is now requesting a positive high five!" CLR_RMV << std::endl;
}
