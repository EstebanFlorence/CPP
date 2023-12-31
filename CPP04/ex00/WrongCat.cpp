#include "WrongCat.hpp"

WrongCat::WrongCat()
//: _type("WrongCat")
{
	std::cout << ITALIC "WrongCat Default Constructor" CLR_RMV << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << ITALIC "WrongCat Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << ITALIC "WrongCat Default Destructor" CLR_RMV << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG MIAO" << std::endl;
}
