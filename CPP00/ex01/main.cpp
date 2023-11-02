#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phone;

	std::cout << GREEN "Welcome " << std::getenv("USER") << "!\n" CLR_RMV << std::endl;
	while (42)
		phone.pressButton();
	return (0);
}
