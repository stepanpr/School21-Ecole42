

#include "PowerFist.hpp"

//==================================CANONIC=FORM===============================

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50), _Name("Power Fist"), _Damage(50), _AP(8) {}

PowerFist::PowerFist(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage), _Name(name), _Damage(damage), _AP(apcost) {}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	*this = src;
}

PowerFist &PowerFist::operator= (const PowerFist& rhs)
{
	if (this != &rhs)
	{
		this->_AP = rhs._AP;
		this->_Damage = rhs._Damage;
		this->_Name = rhs._Name;
	}
	return (*this);
}	

PowerFist::~PowerFist() {}

//====================================ACTIONS===================================

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
