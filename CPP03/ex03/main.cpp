#include "DiamondTrap.hpp"

DiamondTrap	DiamondInnit(std::string& input)
{
	std::cout << MAGENTA "DiamondTrap name > ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "\r\033[A\33[2K";
		std::cin.clear();
		input = "DefaultDiamond";
	}
	DiamondTrap	diamond(input);
	std::cout << CLR_RMV << std::flush;

	return diamond;
}

FragTrap	FragInnit(std::string& input)
{
	std::cout << RED "FragTrap name > ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "\r\033[A\33[2K";
		std::cin.clear();
		input = "DefaultFrag";
	}
	FragTrap	frag(input);
	std::cout << CLR_RMV << std::flush;

	return frag;
}

ScavTrap	ScavInnit(std::string& input)
{
	std::cout << BLUE "ScavTrap name > ";
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
	std::cout << YELLOW "ClapTrap name > ";
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


	std::cout << GREEN "ClapTrap4.0" CLR_RMV << std::endl;
	while (42)
	{
		ClapTrap	clap = ClapInnit(input);
		ScavTrap	scav = ScavInnit(input);
		FragTrap	frag = FragInnit(input);
		DiamondTrap	diamond = DiamondInnit(input);

		scav.guardGate();
		clap.attack(scav.getName());
		scav.takeDamage(0);
		frag.highFivesGuys();
		diamond.whoAmI();

		std::cout << "Ok? [Y/...]" << std::endl;
		std::getline(std::cin, input);
		if (input == "y" || input == "Y" || input == "yes")
			break ;
	}

	return 0;
}
