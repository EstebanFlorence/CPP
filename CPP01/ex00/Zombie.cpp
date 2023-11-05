#include "Zombie.hpp"

Zombie::Zombie(std::string newName): name(newName) {}

Zombie::~Zombie()
{
	std::cout << name << ": Rrrggwwwhuaaa... [destroyed]" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
