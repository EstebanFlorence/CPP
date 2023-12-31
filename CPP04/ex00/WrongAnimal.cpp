#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: _type("Generic WrongAnimal")
{
	std::cout << ITALIC "WrongAnimal Default Constructor" CLR_RMV << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << ITALIC "WrongAnimal Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << ITALIC "WrongAnimal Default Destructor" CLR_RMV << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "GENERIC WRONG ANIMAL SOUND" << std::endl;
}

const std::string&	WrongAnimal::getType() const
{ return _type; }
