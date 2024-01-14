#include "Dog.hpp"

Dog::Dog()
{
	std::cout << ITALIC "Dog Default Constructor" CLR_RMV << std::endl;
	Animal::_type = "Dog";
	_type = "Cane Catanese";
}

Dog::Dog(const Dog& copy)
{
	std::cout << ITALIC "Dog Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << ITALIC "Dog Destructor" CLR_RMV << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "MBAURE!" << std::endl;
}
