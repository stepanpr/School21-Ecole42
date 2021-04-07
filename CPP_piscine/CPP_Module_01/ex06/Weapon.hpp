
//
// CPP_Mod01_ex06/21school/emabel
//

#ifndef	WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>


class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		std::string getType() const;       //возвращает текущий тип оружия
		void setType(std::string type);	   //устанавливает тип оружия
};


#endif