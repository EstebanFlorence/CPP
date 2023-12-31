#include "Animal.hpp"

Animal::Animal()
: _type("Generic Animal")
{
	std::cout << ITALIC "Animal Default Constructor" CLR_RMV << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << ITALIC "Animal Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << ITALIC "Animal Default Destructor" CLR_RMV << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "GENERIC ANIMAL SOUND" << std::endl;
}

const std::string&	Animal::getType() const
{ return _type; }
