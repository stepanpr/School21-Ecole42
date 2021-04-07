
#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *pony;
	pony = new Pony("Rubin", "male", "asturian", "black");
	pony->getName();
	pony->getSex();
	pony->getBreed();
	pony->getColor();
	pony->eating();
	pony->trotting();
	delete(pony);
}

void ponyOnTheStack()
{
	Pony pony("Zorya", "female", "bali", "white");
	pony.getName();
	pony.getSex();
	pony.getBreed();
	pony.getColor();
	pony.eating();
	pony.trotting();

}

int main()
{
	std::string cmd;

	while (1)
	{
		std::cout << std::endl << "\e[0;32mWhat type of Pony do you want?\e[0m" << std::endl
			<< "\e[0;32m(enter the number or enter \"exit\" for exit)\e[0m" << std::endl
			<< "\e[0;32m1. ponyOnTheHeap\e[0m" << std::endl
			<< "\e[0;32m2. ponyOnTheStack\e[0m" << std::endl;
		std::cin >> cmd;
		if (cmd == "1")
		{
			std::cout << "\e[4;94mPONY ON THE HEAP\e[0m" << std::endl;
			ponyOnTheHeap();
			std::cout << "..." << std::endl;
		}
		if (cmd == "2")
		{
			std::cout << "\e[4;94mPONY ON THE STACK\e[0m" << std::endl;
			ponyOnTheStack();
			std::cout << "..." << std::endl;
		}
		if (cmd == "exit")
			break ;
	}
	return (0);
}