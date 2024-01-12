#include "ClapTrap.hpp"

int	main()
{
	std::string	input;

	std::cout << GREEN "ClapTrap 1.0" CLR_RMV << std::endl;
	while (42)
	{
		std::cout << BLUE "Attacker name" CLR_RMV " > " << std::flush;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		else if (input == "exit")
			break;
		ClapTrap	attacker(input);

		std::cout << RED "Defender name" CLR_RMV " > " << std::flush;
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		ClapTrap	defender(input);

		attacker.attack(defender.getName());
		defender.takeDamage(attacker.getAttackDamage());
		defender.beRepaired(5);
	}

	return 0;
}
