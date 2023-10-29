#include "PhoneBook.hpp"

int	main()
{
	static int	i = 0;
	std::string	button;
	PhoneBook	phone;

	std::cout << PURPLE "💈 Welcome " << std::getenv("USER") << "! 💈\n" CLR_RMV << std::endl;
	while (std::getline(std::cin, button))
	{
		//phone.displayBook();
		if (button == "ADD" && phone.addContact(i++))
			;
		if (button == "SEARCH")
			phone.searchContact();
		if (button == "EXIT")
			return (phone.exitPhone());
	}

	return (0);
}
