#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <iomanip>

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string newName);
		~Zombie();

		void	announce();

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif