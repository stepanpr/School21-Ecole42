
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {}
ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	// Zombie *new_zombie = new Zombie(name, this->type);
	// delete(new_zombie);
	// new_zombie->announce();
	// new Zombie(name, this->type);
	return (new Zombie(name, this->type)); 
}

void ZombieEvent::enter(char *string)
{
	int i;
	i = -1;
	while (string)
	{
		string[i] = std::cin.get();
		if (string[i] == 0x0A)
			break ;
		++i;
	}
	string[i] = 0;
}

std::string ZombieEvent::names[5] = {"Antuan", "Lame", "Black King", "Terrible Joe", "Nibbler"};

//случайный зомби созданный на стеке
void ZombieEvent::randomChump()
{
	char *string;
	std::cout << "\e[0;36m❗ Attention! Another spooky zombie comes out!!!\e[0m" << std::endl;
	Zombie zombieBoss(this->names[std::rand() % 5], "boss of zombies");
	std::cout << "\e[0;36mPress ENTER to kill him!!! 💣 \e[0m" << std::endl;
	this->enter(string);
}
