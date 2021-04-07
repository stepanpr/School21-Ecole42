
#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string name;						//имя текущего зомби
	std::string type;						//тип текущего зомби
	static std::string names[5];			//массив случайных имен для зомби

public:

	ZombieEvent();
	~ZombieEvent();

	void setZombieType(std::string type);	 //задает тип зомби (в маине при вводе пользователем)
	Zombie* newZombie(std::string name);     //создает зомби с выбранным типом

	void randomChump();                      //создаст зомби со случайным именем и заставит объявить о себе
	void enter(char *string);

};

#endif
