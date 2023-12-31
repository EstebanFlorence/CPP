#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"

class	WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		void		makeSound() const;	// non virtual
		const std::string&	getType() const;
};

#endif