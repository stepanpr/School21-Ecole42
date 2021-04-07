

//
// CPP_Mod04_ex01/emabel/21school
//

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
# include <string>

class AWeapon
{
	private:
		std::string _Name;
		int _Damage;
		int _AP;
		AWeapon();
	public:
		/* canonical */
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		AWeapon &operator= (const AWeapon& rhs);
		virtual ~AWeapon();

		/* getters */
		std::string getName() const;
		int getAPCost() const;
		int getDamage() const;

		/* actions */
		virtual void attack() const = 0; //абстрактный класс, функция определяется в дочерних классах
};

#endif