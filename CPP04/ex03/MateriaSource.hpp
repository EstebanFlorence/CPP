#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static const int	materiaSize = 4;
		int					learnedMaterias;
		AMateria*			materias[materiaSize];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& other);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif
