#include "AAnimal.hpp"

AAnimal::AAnimal()
: _type("Generic AAnimal")
{
	std::cout << ITALIC << getType() << "Default Constructor" CLR_RMV << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << ITALIC "AAnimal Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << ITALIC "AAnimal Destructor" CLR_RMV << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		AAnimal::operator=(other);
	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout << "GENERIC AANIMAL SOUND" << std::endl;
}

const std::string&	AAnimal::getType() const
{ return _type; }
