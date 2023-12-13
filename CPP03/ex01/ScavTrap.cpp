#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been created (Default Constructor)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
//: ClapTrap(copy)
{
	std::cout << "ScavTrap " << _name << " has been created (Copy Constructor)" << std::endl;
	*this = copy;	
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created (Parameterized Constructor)" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed (Default Destructor)" << std::endl;
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
    std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
}
