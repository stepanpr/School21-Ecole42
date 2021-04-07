
#include "AWeapon.hpp"

//==================================CANONIC=FORM===============================

AWeapon::AWeapon() : _Name("Default player"), _Damage(0), _AP(0) {}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _Name(name), _Damage(damage), _AP(apcost) {}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon &AWeapon::operator= (const AWeapon& rhs)
{
	if (this != &rhs)
	{
		this->_AP = rhs._AP;
		this->_Damage = rhs._Damage;
		this->_Name = rhs._Name;
	}
	return (*this);
}

AWeapon::~AWeapon() {}

//====================================GETTERS===================================

std::string AWeapon::getName() const { return this->_Name; }
int AWeapon::getAPCost() const { return this->_AP; }
int AWeapon::getDamage() const { return this->_Damage; }
