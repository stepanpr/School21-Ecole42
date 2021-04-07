
#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon; //используем указалетель, так как поле _weapon устанавливаем уже после создания экземпляра класса HumanB

	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif
