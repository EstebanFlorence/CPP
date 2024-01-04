#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"

class	Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		const std::string&	getType() const;

		virtual void		makeSound() const;
		virtual Brain*		getBrain() const = 0;
};

#endif