
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
	this->announce();
}

Zombie::~Zombie() 
{
	std::cout << "\e[0;94m" << this->name << "\e[0m 🧟💬: Nooooo" <<  std::endl;
}

void Zombie::announce()
{
	std::cout << "\e[0;36mEnters zombie\e[0m \e[0;94m" << this->name 
	<< "\e[0m \e[0;36m... is\e[0m \e[0;94m" << this->type 
	<< "\e[0m... " << std::endl << "🧟💬: Braiiiiiiinnnssss ..." <<  std::endl;
}
