#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
	std::cout << ITALIC "ScavTrap " << _name << " Default Constructor" CLR_RMV << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << ITALIC "ScavTrap " << _name << " Copy Constructor" CLR_RMV << std::endl;
	*this = copy;	
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	std::cout << ITALIC "ScavTrap " << _name << " Parameterized Constructor" CLR_RMV << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << ITALIC "ScavTrap " << _name << " Destructor" CLR_RMV << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
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

void	ScavTrap::guardGate()
{
    std::cout << BOLD "ScavTrap " << _name << " is now in Gatekeeper mode!" CLR_RMV << std::endl;
}
