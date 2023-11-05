#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <iomanip>

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define GREEN_DARK "\033[0;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon::Weapon(const std::string name);
		Weapon::~Weapon();

		const std::string	&getType() const;
		void				setType();

};

#endif