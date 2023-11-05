#include "Zombie.hpp"

int	zombieName(std::string &alloc, std::string &newName)
{
	std::string	in;

	std::cout << "Zombie name?" << std::endl;
	std::getline(std::cin, in);
	std::cout << "\r\033[A\33[2K\r\033[A\33[2K";
	if (in.empty())
	{
		alloc.clear();
		std::cout << CLR_RMV << std::flush;
		return (1);
	}
	newName = in;
	return (0);
}

int	main()
{
	std::string	in;
	std::string	newName;

	std::cout << PURPLE "🧟 WeeeelllccoooommM... 🧟" CLR_RMV << std::endl;
	std::cout << RED "Heap [H/1]" CLR_RMV " or " BLUE "Stack [S/2] ?" CLR_RMV << std::endl;
	while (std::getline(std::cin, in))
	{
		std::cout << "\r\033[A\33[2K";
		if (in == "1" || in == "h" || in == "H")
		{
			std::cout << RED;
			if (zombieName(in, newName))
				continue ;
			Zombie	*zombie = newZombie(newName);
			zombie->announce();
			delete zombie;
			std::cout << CLR_RMV << std::flush;
		}
		else if (in == "2" || in == "s" || in == "S")
		{
			std::cout << BLUE;
			if (zombieName(in, newName))
				continue ;
			randomChump(newName);
			std::cout << CLR_RMV << std::flush;
		}
		else if (in == "q" || in == "3")
			return (0);
		in.clear();
	}

	return (0);
}