#include "Character.hpp"

Character::Character()
: name(""), garbageCount(0)
{
	std::cout << ITALIC "Character Default Constructor" CLR_RMV << std::endl;
	for (int i = 0; i < inventorySize; i++)
		inventory[i] = NULL;
	for (int i = 0; i < floorSize; i++)
		floor[i] = NULL;
}

Character::Character(const Character& copy)
{
	std::cout << ITALIC << getName() << " Character Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Character::Character(const std::string& name)
: name(name), garbageCount(0)
{
	std::cout << ITALIC << getName() << " Character Parameterized Constructor" CLR_RMV << std::endl;
	for (int i = 0; i < inventorySize; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << ITALIC << getName() << " Character Destructor" CLR_RMV << std::endl;
	for (int i = 0; i < inventorySize; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	for (int i = 0; i < garbageCount; i++)
		delete floor[i];
}

Character&	Character::operator=(const Character& other)
{
	std::cout << ITALIC << getName() << " Character Copy Assignment operator" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.getName();
	for (int i = 0; i < inventorySize; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = other.inventory[i];
	}
	return *this;
}

const std::string&	Character::getName() const
{ return name; }

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < inventorySize; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << inventory[i]->getType() << " equipped from " << getName() << std::endl;
			return ;
		}
	}
	std::cout << "Full inventory! " << getName() << " is unable to equip " << m->getType() << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= inventorySize)
		return ;
	if (inventory[idx])
	{
		std::cout << inventory[idx]->getType() << " unequipped from " << getName() << std::endl;
		floor[garbageCount++] = inventory[idx];
		inventory[idx] = NULL;
	}
	if (garbageCount > floorSize)
		std::cout << "Too much garbage!" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 && idx >= inventorySize)
		return ;
	if (inventory[idx])
	{
		inventory[idx]->use(target);
		unequip(idx);
	}
}
