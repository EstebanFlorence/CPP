#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap " << _name << " has been created (Default Constructor)" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
//: ClapTrap(copy)
{
	std::cout << "FragTrap " << _name << " has been created (Copy Constructor)" << std::endl;
	*this = copy;	
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created (Parameterized Constructor)" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed (Default Destructor)" << std::endl;
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
    std::cout << "FragTrap " << _name << " is now requesting a positive high five!" << std::endl;
}
