#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"

class	Brain
{
	private:
		static const int	numOfIdeas = 100;
		std::string			ideas[numOfIdeas];

	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();

		Brain&	operator=(const Brain& other);

};

#endif
