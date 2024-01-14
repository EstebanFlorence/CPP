#include "Dog.hpp"

Dog::Dog()
: brain(new Brain())
{
	std::cout << ITALIC "Dog Default Constructor" CLR_RMV << std::endl;
	AAnimal::_type = "Dog";
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
	delete brain;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this == &other)
		return *this;
	AAnimal::operator=(other);
	this->brain = new Brain(*other.brain);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "MBAURE!" << std::endl;
}

Brain*	Dog::getBrain() const
{ return brain; }
