#ifndef AAANIMAL_HPP
# define AAANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"

class	AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal& other);

		const std::string&	getType() const;

		virtual void		makeSound() const = 0;
		virtual Brain*		getBrain() const = 0;
};

#endif