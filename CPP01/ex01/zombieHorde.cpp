#include "Zombie.hpp"

Zombie*	zombieHorde( int n, std::string name )
{
	Zombie	*horde = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		std::stringstream	ss;
		ss << name << i + 1;
		horde[i].setName(ss.str());
	}
	return (horde);
}
