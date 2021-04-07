
#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"


class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon; //используем ссылку, так как поле _weapon устанавливаем при создании экземпляра класса HumanA
						 //хотя в данной ситуации возможно использовать и указатель

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif