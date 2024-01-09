#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << ITALIC "AMateria Default Constructor" CLR_RMV << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << ITALIC "AMateria Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

AMateria::AMateria(const std::string& type)
: type(type)
{
	std::cout << ITALIC << getType() << " AMateria Parameterized Constructor" CLR_RMV << std::endl;
}

AMateria::~AMateria()
{
	std::cout << ITALIC << getType() << " AMateria Destructor" CLR_RMV << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << ITALIC << getType() << " AMateria Copy Assignment operator" CLR_RMV << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

const std::string&	AMateria::getType() const
{ return  type; }

void	AMateria::use(ICharacter& target)
{
	std::cout << BOLD "* uses " << type << "at " << target.getName() << " *" CLR_RMV << std::endl;
}
