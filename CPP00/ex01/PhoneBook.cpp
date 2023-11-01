#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}



int	PhoneBook::addContact(int i)
{
	std::string	line;

	std::cout << BLUE "Enter the following fields:" CLR_RMV << std::endl;

	std::getline(std::cin, line);
	std::cout << "First name: ";
	if (contacts[i].setFname(line))
		return (errorPhone());
	line.clear();

	std::getline(std::cin, line);
	std::cout << "Last name: ";
	if (contacts[i].setLname(line))
		return (errorPhone());
	line.clear();

	std::getline(std::cin, line);
	std::cout << "Nickname: ";
	if (contacts[i].setNickname(line))
		return (errorPhone());
	line.clear();

	std::getline(std::cin, line);
	std::cout << "Phone number: ";
	if (contacts[i].setNumber(line))
		return (errorPhone());
	line.clear();

	std::getline(std::cin, line);
	std::cout << "Darkest secret: ";
	if (contacts[i].setSecret(line))
		return (errorPhone());
	line.clear();
	

}

int	PhoneBook::pressButton()
{
	static int	i = 0;
	std::string	button;

	while (std::getline(std::cin, button))
	{
		//phone.displayBook();
		if (button == "ADD" && addContact(i++))
			;
		if (button == "SEARCH")
			searchContact();
		if (button == "EXIT")
			return (exitPhone());
	}

}

void	PhoneBook::searchContact()
{

}

void	PhoneBook::displayBook()
{
	
}

int	PhoneBook::errorPhone()
{
	std::cerr << RED "Error" CLR_RMV << std::endl;
	return (1);
}

int	PhoneBook::exitPhone()
{
	std::cout << PURPLE "Exiting phone... Goodbye!" CLR_RMV << std::endl;
	return (0);
}
