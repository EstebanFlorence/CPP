#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(const AMateria& copy);
		AMateria(const std::string& type);
		virtual ~AMateria();

		AMateria&	operator=(const AMateria& other);

		const std::string&	getType() const;

		virtual AMateria*	clone() const = 0;
		// virtual void		use();
};

#endif
