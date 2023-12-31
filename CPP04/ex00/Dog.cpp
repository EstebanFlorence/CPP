#include "Dog.hpp"

Dog::Dog()
{
	std::cout << ITALIC "Dog Default Constructor" CLR_RMV << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	std::cout << ITALIC "Dog Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << ITALIC "Dog Default Destructor" CLR_RMV << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "MBAURE!" << std::endl;
}
