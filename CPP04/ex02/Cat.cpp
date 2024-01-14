#include "Cat.hpp"

Cat::Cat()
: brain(new Brain())
{
	std::cout << "Cat Default Constructor" CLR_RMV << std::endl;
	AAnimal::_type = "Cat";
	_type = "Gato Carioca";
}

Cat::Cat(const Cat& copy)
{
	std::cout << ITALIC "Cat Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << ITALIC "Cat Destructor" CLR_RMV << std::endl;
	delete brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	AAnimal::operator=(other);
	this->brain = new Brain(*other.brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "IRMIAO!" << std::endl;
}

Brain*	Cat::getBrain() const
{ return brain; }
