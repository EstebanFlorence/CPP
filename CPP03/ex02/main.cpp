#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* 
void	FragInnit()
{
	
}

void	ScavInnit()
{
	
}

void	ClapInnit()
{

}
 */

int	main()
{
	std::string	input;

	std::cout << GREEN "ClapTrap2.0" CLR_RMV << std::endl;
	while (42)
	{
		std::cout << "ClapTrap name > ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		else if (input == "q")
			break;
		ClapTrap	clap(input);

		std::cout << "ScavTrap name > ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		ScavTrap	scav(input);

		std::cout << "FragTrap name > ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		FragTrap	frag(input);

		scav.guardGate();
		clap.attack(scav.getName());
		scav.takeDamage(0);
		frag.highFivesGuys();
	}


	return 0;
}
