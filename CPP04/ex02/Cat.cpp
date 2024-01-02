#include "Cat.hpp"

Cat::Cat()
: brain(new Brain())
{
	std::cout << ITALIC "Cat Default Constructor" CLR_RMV << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << ITALIC "Cat Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << ITALIC "Cat Default Destructor" CLR_RMV << std::endl;
	delete brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	this->_type = other._type;
	this->brain = other.brain;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "IRMIAO!" << std::endl;
}

Brain*	Cat::getBrain() const
{ return brain; }
