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
{
	std::cout << ITALIC "AMateria Parameterized Constructor: " << this->type << CLR_RMV << std::endl;
}

AMateria::~AMateria()
{
	std::cout << ITALIC "AMateria Default Destructor" CLR_RMV << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

const std::string&	AMateria::getType() const
{ return  type; }

// void	AMateria::use()
// {

// }
