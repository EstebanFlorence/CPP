#include "Brain.hpp"

Brain::Brain()
{
	std::cout << ITALIC "Brain Default Constructor" CLR_RMV << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << ITALIC "Brain Copy Constructor" CLR_RMV << std::endl;
	for (int i = 0; i < numOfIdeas; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain::~Brain()
{
	std::cout << ITALIC "Brain Destructor" CLR_RMV << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < numOfIdeas; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

int	Brain::getMaxIdeas() const
{ return numOfIdeas; }
