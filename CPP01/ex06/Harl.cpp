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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(int level)
{
	switch (level)
	{
		case 0:
			(this->*levelsLog[0])();
		case 1:
			(this->*levelsLog[1])();
		case 2:
			(this->*levelsLog[2])();
		case 3:
			(this->*levelsLog[3])();
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
