#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << ITALIC "DiamondTrap " << _name << " Default Constructor" CLR_RMV << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout << ITALIC "DiamondTrap " << _name << " Copy Constructor" CLR_RMV << std::endl;
	*this = copy;	
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << ITALIC "DiamondTrap " << _name << " Parameterized Constructor" CLR_RMV << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << ITALIC "DiamondTrap " << _name << " Default Destructor" CLR_RMV << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	//	ClapTrap::_name = other._name + "_clap_name";
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << BOLD << _name << ": \"I'm " << ClapTrap::_name << "\"" CLR_RMV << std::endl;
}
