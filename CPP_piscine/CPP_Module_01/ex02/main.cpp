
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

std::string choiceOfType(std::string &cmd)
{
	if (cmd == "1")
		return ("big and fat");
	if (cmd == "2")
		return ("small and thin");
	if (cmd == "3")
		return ("big and thin");
	if (cmd == "4")
		return ("small and fat");
	return (0);
}

int main(void)
{
	ZombieEvent event;
	std::string cmd;
	char *string = new char;

	std::cout << "\e[0;36mWelcome to ZombiePark! are you ready to see it? (y/n)\e[0m" << std::endl;
	std::cin >> cmd;
	if (cmd == "n")
		std::cout << "\e[0;36mOk, goodluck!\e[0m" << std::endl;
	else if (cmd == "y")
	{
		while (1)
		{
			std::cout << "\e[0;36mWhat kind of zombie do you want to see?\e[0m " << std::endl 
				<< "\e[0;94m1. big and fat\e[0m" << std::endl
				<< "\e[0;94m2. small and thin\e[0m" << std::endl
				<< "\e[0;94m3. big and thin\e[0m" << std::endl
				<< "\e[0;94m4. small and fat\e[0m" << std::endl
				<< "\e[0;36mplease, enter the number of type of zombie or EXIT for exit...\e[0m" << std::endl;
			std::cin >> cmd;
			if (cmd == "EXIT")
			{
				std::cout << "\e[0;36mGoodluck!\e[0m" << std::endl;
				return (0);
			}
			if (cmd != "1" && cmd != "2" && cmd != "3" && cmd != "4")
			{
				std::cout << "\e[0;36mPlease, try againe...\e[0m" << std::endl;
				continue ;
			}
			else
				{
					event.setZombieType(choiceOfType(cmd));
					std::cout << "\e[0;36mplease, come up with a name for him... (enter the name without spaces)\e[0m" << std::endl;
					std::cin >> cmd;
					std::cout << "..." << std::endl;
					Zombie *my_zombie = event.newZombie(cmd);
					std::cout << "\e[0;36mDo you want to kill him? 💣 (y/n)\e[0m" << std::endl;
					std::cin >> cmd;
					if (cmd == "n")
					{
						std::cout << "\e[0;36mIt's a shame, but zombie will die of hunger anyway...\e[0m" << std::endl;
						delete(my_zombie);
						std::cout << "press ENTER to continue" << std::endl;
						cmd = std::cin.get();
						event.enter(string);
						continue ;
					}
					else if (cmd == "y")
					{
						delete(my_zombie);
						std::cout << "✅ \e[0;36mSuccessfully!\e[0m" <<  std::endl;
						std::cout << "press ENTER to continue" << std::endl;
						cmd = std::cin.get();
						event.enter(string);
						event.randomChump();
						std::cout << "✅ \e[0;36mSuccessfully!!!\e[0m" <<  std::endl;
						std::cout << "press ENTER to continue" << std::endl;
						event.enter(string);
						std::cout << "..." << std::endl;
					}
				}
		}
		delete(string);
	}
	else 
	{
		std::cout << "\e[0;36mI dont't understand you.. Bye!\e[0m" << std::endl;
		return (0);
		delete(string);
	}
	return (0);
}
