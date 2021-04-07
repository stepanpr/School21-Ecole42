
#include "SuperMutant.hpp"

//==================================CANONIC=FORM===============================

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(int hp, std::string const & type) : Enemy(hp, type) 				//функция запривачена, так как поля _HP _Type по умолчанию менять нельзя
{
	this->setHP(hp);
	this->setType(type);
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src) : Enemy(src.getHP(), src.getType())
{
	*this = src;
}

SuperMutant &SuperMutant::operator= (const SuperMutant& rhs)
{
	if (this != &rhs)
	{
		this->setHP(rhs.getHP());
		this->setType(rhs.getType());
	}
	return (*this);
}	

SuperMutant::~SuperMutant()
{

	std::cout << "Aaargh..." << std::endl;
}

//====================================ACTIONS===================================

void SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	Enemy::takeDamage(damage);
	return ;
}
