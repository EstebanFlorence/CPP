#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor" CLR_RMV << std::endl;
	Animal::_type = "Cat";
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
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "IRMIAO!" << std::endl;
}
