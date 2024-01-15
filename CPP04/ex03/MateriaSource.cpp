#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
: learnedMaterias(0)
{
	std::cout << ITALIC "MateriaSource Default Constructor" CLR_RMV << std::endl;
	for (int i = 0; i < materiaSize; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << ITALIC "MateriaSource Copy Constructor" CLR_RMV << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << ITALIC "MateriaSource Destructor" CLR_RMV << std::endl;
	for (int i = 0; i < materiaSize; i++)
	{
		if (materias[i])
			delete materias[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << ITALIC "MateriaSource Copy Assignment operator" CLR_RMV << std::endl;
	if (this == &other)
		return *this;
	this->learnedMaterias = other.learnedMaterias;
	for (int i = 0; i < materiaSize; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < materiaSize; i++)
	{
		if (!materias[i])
		{
			materias[i] = m;
			learnedMaterias++;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < learnedMaterias; i++)
	{
		if (materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
