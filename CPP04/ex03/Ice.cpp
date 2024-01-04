#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{
	std::cout << ITALIC "Ice Default Constructor" CLR_RMV << std::endl;
}

Ice::Ice(const Ice& copy)
{
	std::cout << ITALIC "Ice Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Ice::~Ice()
{
	std::cout << ITALIC "Ice Default Destructor" CLR_RMV << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice*	Ice::clone() const
{ return new Ice(*this); }
