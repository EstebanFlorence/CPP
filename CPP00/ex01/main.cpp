#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phone;

	std::cout << PURPLE "💈 Welcome " << std::getenv("USER") << "! 💈\n" CLR_RMV << std::endl;
	while (phone.pressButton())
		return (0);
	return (0);
}
