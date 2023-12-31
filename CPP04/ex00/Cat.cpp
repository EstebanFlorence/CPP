#include "Cat.hpp"

Cat::Cat()
//: _type("Cat")
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
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "IRMIAO!" << std::endl;
}
