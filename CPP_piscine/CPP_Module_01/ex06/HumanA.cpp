
#include "HumanA.hpp"

//используем инициализатора конструктора, так как в классе присутствует член ссылочного типа &weapon
//(для всех ссылок и констант используем инициализатор класса)
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) // _name(name)
{
	this->_name = name;
}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << "\e[0;36m" << this->_name << " attacks with his " << this->_weapon.getType() << "\e[0m" << std::endl;
}
