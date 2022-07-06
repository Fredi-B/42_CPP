#include "Harl.hpp"

Harl::Harl(void) { }

Harl::~Harl(void) { }

void	Harl::complain(std::string level)
{
	void	(Harl::*fctPtrArr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	level_of_complain[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == level_of_complain[i])
		{
			(this->*fctPtrArr[i])();
			return ;
		}
	}
	std::cout << "Everything is fine." << std::endl;
}

void	Harl::debug(void)
{
	std::cerr << "Debug:" << std::endl;
	std::cerr << "I love having extra bacon for my"
		" 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
			<< std::endl;
}

void	Harl::info(void)
{
	std::cerr << "Info:" << std::endl;
	std::cerr << "I cannot believe adding extra bacon costs more money."
		" You didn’t put enough bacon in my burger!"
		" If you did, I wouldn’t be asking for more!"
			<< std::endl;
}

void	Harl::warning(void)
{
	std::cerr << "Warning:" << std::endl;
	std::cerr << "I think I deserve to have some extra bacon for free."
		" I’ve been coming for years whereas you started working here since last month."
			<< std::endl;
}

void	Harl::error(void)
{
	std::cerr << "Error:" << std::endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}
