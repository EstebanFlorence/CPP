#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define ITALIC "\033[3m"
# define BOLD "\033[1m"
# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[38;5;208m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;95m"

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap(const std::string& name);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string		getName();
		unsigned int	getAttackDamage();
};

#endif