
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string _Name;
		int _NumOfAP;
		AWeapon *_Weapon;
		std::string _CurrentWeapon;
		int _HasWeapon;

	public:
		/* canonical */
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		Character &operator= (const Character& rhs);
		~Character();

		/* getters */
		std::string const getName() const;
		int getNumOfAP() const;
		std::string getWeaponName() const;
		int getHasWeapon() const;

		/* actions */
		void recoverAP();				//перезарядка + 10 AP
		void equip(AWeapon* weapon);	//взять оружие
		void attack(Enemy* enemy);		//атака
		
};


std::ostream &operator<<(std::ostream &out, const Character &tmp);

#endif
