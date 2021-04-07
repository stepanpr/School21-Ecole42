
#include "HumanB.hpp"

//в конструкторе инициилизируем поле _name
HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB() {}

void HumanB::attack()
{
	std::cout << "\e[0;94m" << this->_name << " attacks with his " << this->_weapon->getType() << "\e[0m" << std::endl;
}

//инициилизируем поле _weapon по ссылке
void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
