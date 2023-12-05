#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clap("Ciccio");

	clap.attack("Enemy");
	clap.takeDamage(13);
	clap.beRepaired(5);

	return 0;
}
