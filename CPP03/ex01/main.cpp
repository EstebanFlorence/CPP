#include "ScavTrap.hpp"

ScavTrap	ScavInnit(std::string& input)
{
	std::cout << MAGENTA "ScavTrap name > ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "\r\033[A\33[2K";
		std::cin.clear();
		input = "DefaultScav";
	}
	ScavTrap	scav(input);
	std::cout << CLR_RMV << std::flush;

	return scav;
}

ClapTrap	ClapInnit(std::string& input)
{
	std::cout << CYAN "ClapTrap name > ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "\r\033[A\33[2K";
		std::cin.clear();
		input = "DefaultClap";
	}
	ClapTrap	clap(input);
	std::cout << CLR_RMV << std::flush;

	return clap;
}

int	main()
{
	std::string	input;

	std::cout << ORANGE "ClapTrap 2.0" CLR_RMV << std::endl;
	while (42)
	{
		ClapTrap	clap = ClapInnit(input);
		ScavTrap	scav = ScavInnit(input);

		scav.guardGate();
		clap.attack(scav.getName());
		scav.takeDamage(clap.getAttackDamage());
		scav.attack(clap.getName());
		clap.takeDamage(scav.getAttackDamage());

		std::cout << "The End? [Y/...]" << std::endl;
		std::getline(std::cin, input);
		if (input == "y" || input == "Y" || input == "yes")
			break ;
	}

	return 0;
}
