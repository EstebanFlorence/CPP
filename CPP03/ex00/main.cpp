#include "ClapTrap.hpp"

int	main()
{
	std::string	input;

	std::cout << GREEN "ClapTrap1.0" CLR_RMV << std::endl;
	while (42)
	{
		std::cout << "Attacker name > ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		else if (input == "q")
			break;
		ClapTrap	attacker(input);

		std::cout << "Defender name > ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		ClapTrap	defender(input);

		attacker.attack(defender.getName());
		defender.takeDamage(7);
		defender.beRepaired(5);
	}

	return 0;
}
