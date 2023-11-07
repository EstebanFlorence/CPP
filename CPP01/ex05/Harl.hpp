#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>


# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define GREEN_DARK "\033[0;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

class	Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
		void	(Harl::*levelsLog[4])()/*  =
				{
					&Harl::debug,
					&Harl::info,
					&Harl::warning,
					&Harl::error
				} */;

	public:
		Harl();
		~Harl();

		void	complain(std::string level);


};


#endif