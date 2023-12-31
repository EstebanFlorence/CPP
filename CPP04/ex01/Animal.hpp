#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

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

		virtual void		makeSound() const;
		const std::string&	getType() const;
};

#endif