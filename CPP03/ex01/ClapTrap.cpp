#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << ITALIC "ClapTrap " << _name << " Default Constructor" CLR_RMV << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << ITALIC "ClapTrap " << _name << " Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << ITALIC "ClapTrap " << _name << " Parameterized Constructor" CLR_RMV << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << ITALIC "ClapTrap " << _name << " Destructor" CLR_RMV << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
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

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << BOLD "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" CLR_RMV << std::endl;
		_energyPoints--;
	}
	else
	{
        std::cout << BOLD "ClapTrap " << _name << " can't be repaired.";
		if (!_hitPoints)
			std::cout << " No hit points left!" << std::endl;
		if (!_energyPoints)
			std::cout << " No energy points left!" << std::endl;
		std::cout << CLR_RMV << std::flush;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints = (amount > _hitPoints) ? 0 : _hitPoints - amount;
        std::cout << BOLD "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _hitPoints << CLR_RMV << std::endl;
	}
	else
        std::cout << BOLD "ClapTrap " << _name << " is already dead!" CLR_RMV << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
        std::cout << BOLD "ClapTrap " << _name << " is repaired for " << amount << " points! Hit points: " << _hitPoints << CLR_RMV << std::endl;
	}
	else
	{
        std::cout << BOLD "ClapTrap " << _name << " can't be repaired.";
		if (!_hitPoints)
			std::cout <<" No hit points left!" << std::endl;
		if (!_energyPoints)
			std::cout << " No energy points left!" << std::endl;
		std::cout << CLR_RMV << std::flush;
	}
}

std::string	ClapTrap::getName()
{ return _name; }

unsigned int	ClapTrap::getAttackDamage()
{ return _attackDamage; }