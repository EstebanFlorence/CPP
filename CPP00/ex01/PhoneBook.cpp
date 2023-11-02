#include "PhoneBook.hpp"

int	PhoneBook::errorPhone(int n)
{
	if (n == 1)
		std::cerr << PURPLE "Error: Empty field" CLR_RMV << std::endl;
	if (n == 2)
		std::cerr << PURPLE "There are no contacts yet" CLR_RMV << std::endl;
	if (n == 3)
		std::cerr << PURPLE "Wrong ID" CLR_RMV << std::endl;
	if (n == 4)
		std::cerr << PURPLE "Empty contact" CLR_RMV << std::endl;
	std::cout << std::endl;
	return (1);
}

void	PhoneBook::exitPhone()
{
	std::cout << "Exiting phone..." << std::endl;
	exit (0);
}

void	PhoneBook::displayContact(int i)
{
	if (contacts[i].getFname().empty() && errorPhone(4))
		return ;
	std::cout << "First name: " << contacts[i].getFname() << std::endl;
	std::cout << "Last name: " << contacts[i].getLname() << std::endl;
	std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[i].getNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[i].getSecret() << std::endl;
}

void	PhoneBook::displayBook()
{
	std::cout << "|" << std::setw(10) << std::left << "Index";
	std::cout << "|" << std::setw(10) << std::left << "Name";
	std::cout << "|" << std::setw(10) << std::left << "Surname";
	std::cout << "|" << std::setw(10) << std::left << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		std::cout << "|" << std::setw(10) << std::right << contacts[i].trunContact(contacts[i].getFname());
		std::cout << "|" << std::setw(10) << std::right << contacts[i].trunContact(contacts[i].getLname());
		std::cout << "|" << std::setw(10) << std::right << contacts[i].trunContact(contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

int	PhoneBook::searchContact(int index)
{
	int			in;
	std::string	input;

	if (contacts[0].getFname().empty())
		return (errorPhone(2));
	displayBook();
	std::cout << "Enter Contact ID: ";
	std::getline(std::cin, input);
	in = atoi(input.c_str()) - 1;
	if (in < 0 || in > index)
		return (errorPhone(3));
	displayContact(in);
	return (0);
}

int	PhoneBook::addContact(int &i)
{
	std::string	line;

	std::cout << "Add contact n. " << i + 1 << "\nEnter the following fields:" << std::endl;

	std::cout << BLUE "First name: " CLR_RMV;
	std::getline(std::cin, line);
	if (contacts[i].setFname(line))
		return (errorPhone(1));
	line.clear();

	std::cout << BLUE "Last name: " CLR_RMV;
	std::getline(std::cin, line);
	if (contacts[i].setLname(line))
		return (errorPhone(1));
	line.clear();

	std::cout << BLUE "Nickname: " CLR_RMV;
	std::getline(std::cin, line);
	if (contacts[i].setNickname(line))
		return (errorPhone(1));
	line.clear();

	std::cout << BLUE "Phone number: " CLR_RMV;
	std::getline(std::cin, line);
	if (contacts[i].setNumber(line))
		return (errorPhone(1));
	line.clear();

	std::cout << BLUE "Darkest secret: " CLR_RMV;
	std::getline(std::cin, line);
	if (contacts[i].setSecret(line))
		return (errorPhone(1));
	line.clear();

	std::cout << std::endl;
	(i + 1 < 8) ? i++ : i = 0;
	return (0);
}

void	PhoneBook::displayMenu()
{
	std::cout << "       📞 My Awesome PhoneBook\n";
	std::cout << "      Enter the following commands:\n\n";
	std::cout << "\'" YELLOW "1" CLR_RMV "\' > 👤 ADD CONTACT\n";
	std::cout << "\'" YELLOW "2" CLR_RMV "\' > 🔍 SEARCH CONTACT\n";
	std::cout << "\'" YELLOW "3" CLR_RMV "\' > ❌ EXIT PHONE\n";
	std::cout << std::endl;
}

void	PhoneBook::pressButton()
{
	static int	i = 0;
	std::string	button;

	displayMenu();
	while (std::getline(std::cin, button))
	{
		std::cout << "\r\033[A\33[2K";
		if (button == "1")
			addContact(i);
		else if (button == "2")
			searchContact(i);
		else if (button == "3")
			exitPhone();
		button.clear();
	}

}
