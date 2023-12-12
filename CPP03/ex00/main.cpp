#include "ClapTrap.hpp"

int	main()
{
//	int			n = 0;
	std::string	input;
	ClapTrap	attacker(input);
	ClapTrap	defender(input);

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
//		std::cin.ignore(1000, '\n');

		std::cout << "Defender name > ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "\r\033[A\33[2K";
			std::cin.clear();
			continue ;
		}
		break;
	}
	attacker.attack(defender.getName());
	defender.takeDamage(7);
	defender.beRepaired(5);
	return 0;
}
