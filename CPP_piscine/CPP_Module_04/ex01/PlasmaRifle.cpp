
# include "PlasmaRifle.hpp"

//==================================CANONIC=FORM===============================

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21), _Name("Plasma Rifle"), _Damage(21), _AP(5) {}

PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage), _Name(name), _Damage(damage), _AP(apcost) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	*this = src;
}

PlasmaRifle &PlasmaRifle::operator= (const PlasmaRifle& rhs)
{
		if (this != &rhs)
	{
		this->_AP = rhs._AP;
		this->_Damage = rhs._Damage;
		this->_Name = rhs._Name;
	}
	return (*this);
}	

PlasmaRifle::~PlasmaRifle() {}


//====================================ACTIONS===================================

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
