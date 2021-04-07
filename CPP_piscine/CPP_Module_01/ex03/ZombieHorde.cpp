
#include "ZombieHorde.hpp"
# include "Zombie.hpp"

//функция конструктор
ZombieHorde::ZombieHorde(int N)
{
	this->numOfZombies = N;
	this->zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(ZombieHorde::names[std::rand() % 10]);
		zombies[i].setType(ZombieHorde::types[std::rand() % 4]);
	}
}

//функция деструктор (удаление объектов массива Zombies)
ZombieHorde::~ZombieHorde(void) { delete[] this->zombies; }

//функция вызывающая метод announce() каждого из объектов класса Zombie,
//вызывается в конструкторе
void ZombieHorde::announce() const
{
	for(int i = 0; i < this->numOfZombies; i++)
	{
		this->zombies[i].announce();
	}
}

std::string ZombieHorde::names[10] = {"Antuan", "Lame", "Black King", "Terrible Joe", "Nibbler", "Helen", "Spooky Student", "King of Zombies", "Black Monarch", "Any"};

std::string ZombieHorde::types[4] = {"big and fat", "small and thin", "big and thin", "small and fat"};