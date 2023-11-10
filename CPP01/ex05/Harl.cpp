#include "Harl.hpp"

Harl::Harl()
{
	levelsLog[0] = &Harl::debug;
	levelsLog[1] = &Harl::info;
	levelsLog[2] = &Harl::warning;
	levelsLog[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "DEBUG: love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*levelsLog[i])();
			return ;
		}
	}
	std::cerr << "Wrong command" << std::endl;
}
