#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{
	std::cout << ITALIC "Cure Default Constructor" CLR_RMV << std::endl;

}

Cure::Cure(const Cure& copy)
{
	std::cout << ITALIC "Cure Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

Cure::~Cure()
{
	std::cout << ITALIC "Cure Destructor" CLR_RMV << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	std::cout << ITALIC "Cure Copy Assignment operator" CLR_RMV << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria*	Cure::clone() const
{ return new Cure(*this); }

void	Cure::use(ICharacter& target)
{
	std::cout << BOLD "* heals " << target.getName() << "'s wounds *" CLR_RMV << std::endl;
}
