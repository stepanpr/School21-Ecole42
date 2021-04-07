

#include "RadScorpion.hpp"

//==================================CANONIC=FORM===============================

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" <<std::endl;
}

RadScorpion::RadScorpion(int hp, std::string const & type) : Enemy(hp, type)				//функция запривачена, так как поля _HP _Type по умолчанию менять нельзя
{
	this->setHP(hp);
	this->setType(type);
	std::cout << "* click click click *" <<std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src) : Enemy(src.getHP(), src.getType())
{
	*this = src;
}

RadScorpion &RadScorpion::operator= (const RadScorpion& rhs)
{
	if (this != &rhs)
	{
		this->setHP(rhs.getHP());
		this->setType(rhs.getType());
	}
	return (*this);
}	

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" <<std::endl;

}

//====================================ACTIONS===================================

void RadScorpion::takeDamage(int damage)
{
	Enemy::takeDamage(damage);
}
