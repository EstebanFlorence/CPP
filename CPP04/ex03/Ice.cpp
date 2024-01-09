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
	std::cout << ITALIC "Ice Destructor" CLR_RMV << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << ITALIC "Ice Copy Assignment operator" CLR_RMV << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria*	Ice::clone() const
{ return new Ice(*this); }

void	Ice::use(ICharacter& target)
{
	std::cout << BOLD "* shoots an ice bolt at " << target.getName() << " *" CLR_RMV << std::endl;
}
