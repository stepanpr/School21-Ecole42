
#include "Zombie.hpp"
#include "ZombieHorde.hpp"


int strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

//функция проверки входящего значения
int checkInput(char *input)
{
	for(int i = 0; i < strlen(input); i++)
	{
		if (!isdigit(input[i]))
		{
			std::cout << "\e[0;36mPlease, enter the number!\e[0m " << std::endl;
			return (1);
		}
	}
	return (0);
}

//функция main 
int main()
{
	char *input;

	while (1)
	{
		std::cout << "\e[0;36mHow many zombies do you want to see?\e[0m ";
		std::cin >> input;
		if (checkInput(input))
			continue ;
		else
			break ;
	}
	ZombieHorde zAge(atoi(input));
	zAge.announce();
}
