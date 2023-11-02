#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <iomanip>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();

		void	announce();

};

#endif