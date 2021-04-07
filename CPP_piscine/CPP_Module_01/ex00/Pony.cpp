
#include "Pony.hpp"


Pony::Pony(std::string name, std::string sex, std::string breed, std::string color)
{
	this->name = name;
	this->sex = sex;
	this->breed = breed;
	this->color = color;
}

Pony::~Pony() {}

void Pony::getName()
{
	std::cout << std::setw(20) << "\e[0;94mname:\e[0m " << this->name << std::endl;
}

void Pony::getSex()
{
	std::cout  << std::setw(20) << "\e[0;94msex:\e[0m " << this->sex << std::endl;
}

void Pony::getBreed()
{
	std::cout  << std::setw(20) << "\e[0;94mbreed:\e[0m " << this->breed << std::endl;
}

void Pony::getColor()
{
	std::cout << std::setw(20) << "\e[0;94mcolor:\e[0m " << this->color << std::endl;
}

void Pony::trotting()
{
	std::string cmd;

	std::cout << "\e[0;36m 💬 Do you want to walk with " << this->name
			<< "? (y/n)\e[0m" << std::endl;
	while (1)
	{
		std::cin >> cmd;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
			std::cout << "\e[0;36m 💬 tnahks, but " << this->name 
					<< " is not eat this... please give no more than ten apples...\e[0m" 
					<< std::endl;
		}
		if (cmd == "n")
		{
			std::cout << "\e[0;36m 💬 Ok, see you later!\e[0m" << std::endl;
			break ;
		}
		else if (cmd == "y")
		{
			std::cout << "\e[0;36m ⛰️  " << this->name << " is trotting very fast 🐎\e[0m" << std::endl;
			break ;
		}
		else
		{
			std::cout << "\e[0;36m 💬 I don't undersand you... Bye!\e[0m" << std::endl;
			break ;
		}
	}
}

void Pony::eating()
{
	int num;
	std::cout << "\e[0;36m 💬 give some apples for " << this->name
			<< " please..." << std::endl << "(enter how many apples you will give)\e[0m" << std::endl;

	while (1)
	{
		std::cin >> num;
		if (std::cin.fail() || num <= 0)
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
			std::cout << "\e[0;36m 💬 tnahks, but " << this->name 
					<< " is not eat this... please give no more than ten apples...\e[0m" 
					<< std::endl;
		}
		else if (num > 10)
			std::cout << "\e[0;36m 💬 is so musch!!! please give no more than ten...\e[0m" << std::endl;

		else
		{
			std::cout << "\e[0;36m 💬 " << this->name << " now is is eatig ";
			for (int i = 0; i < num; i++)
				std::cout << "🍏";
			if (num == 1)
				std::cout << " apple! Thank You!\e[0m" << std::endl;
			else if (num > 1)
				std::cout << " apples! Thank You!\e[0m" << std::endl;
			break ;
		}
	}
}