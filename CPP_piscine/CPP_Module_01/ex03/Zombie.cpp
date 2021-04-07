
#include "Zombie.hpp"

//функция конструктор по умолчанию
Zombie::Zombie(void) {  }

//функция деструктор
Zombie::~Zombie(void) 
{
	std::cout << "\e[0;94m" << this->name 
	<< "\e[0m  \e[0;36mdies before reaching you...\e[0m 🧟💬: Nooooo" 
	<<  std::endl;
}

//функция установки значения поля name
void Zombie::setName(std::string name) { this->name = name; }

//функция установки значения поля type
void Zombie::setType(std::string type) { this->type = type; }

//функция выводящая "приветственное сообщение" от объекта класса
void Zombie::announce()
{
	std::cout << "\e[0;36mEnters zombie\e[0m \e[0;94m" << this->name 
	<< "\e[0m \e[0;36m... is\e[0m \e[0;94m" << this->type 
	<< "\e[0m... " << "🧟💬: Braiiiiiiinnnssss ..." <<  std::endl;
}

