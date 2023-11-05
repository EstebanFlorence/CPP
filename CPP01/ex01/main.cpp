#include "Zombie.hpp"

int	main()
{
	int			n = 0;
	std::string	name;
	Zombie		*horde;

	std::cout << PURPLE "🧟 WeeeelllccoooommM... 🧟" CLR_RMV << std::endl;

	while (!n)
	{
		std::cout << "Hoow biiigg hhooordde?" << std::endl;
		std::cin >> n;
		//std::cout << "\r\033[A\33[2K\r\033[A\33[2K";
		if (!n)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue ;
		}
		//std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Zombies name?" << std::endl;
		std::getline(std::cin, name);
		//std::cout << "\r\033[A\33[2K\r\033[A\33[2K";
		if (name.empty())
		{
			n = 0;
			continue ;
		}
	}
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
