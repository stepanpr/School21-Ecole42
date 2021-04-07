

#include "Character.hpp"

//==================================CANONIC=FORM===============================

Character::Character() : _Name("Default player"), _NumOfAP(40), _HasWeapon(0) {}

Character::Character(std::string const & name) : _Name(name), _NumOfAP(40), _HasWeapon(0) {}

Character::Character(Character const & src)
{
	*this = src;
}

Character &Character::operator= (const Character& rhs)
{
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
	}
	return (*this);
}	

Character::~Character() {}

//====================================GETTERS===================================

std::string const Character::getName() const { return this->_Name; }
int Character::getNumOfAP() const { return this->_NumOfAP; }
std::string Character::getWeaponName() const { return this->_Weapon->getName(); }
int Character::getHasWeapon() const { return this->_HasWeapon; }

//====================================ACTIONS===================================


void Character::recoverAP()
{
	if (this->_NumOfAP < 40)  
	{
		if (this->_NumOfAP + 10 > 40)
		{
			this->_NumOfAP = 40;
			return ;
		}
		else 
		{
			this->_NumOfAP += 10;
			return ;
		}
	}
	else if (this->_NumOfAP >= 40)
		std::cout << "AP is full!" << std::endl;
}

void Character::equip(AWeapon* weapon)
{
	if ((this->_Weapon = weapon))
		this->_HasWeapon = 1;
}

void Character::attack(Enemy* enemy)
{

	if (this->_NumOfAP - this->_Weapon->getAPCost() < 0)
		return ;
	this->_NumOfAP -= this->_Weapon->getAPCost();		//уменьшаем AP

	std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->_Weapon->getName() << std::endl;
	this->_Weapon->attack();

	// enemy->setHP(enemy->getHP() - this->_Weapon->getDamage());
	// if (enemy->getHP() <= 0)
	// 	delete(enemy);
	enemy->takeDamage(this->_Weapon->getDamage());

}


//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<<(std::ostream &out, const Character &character)
{
	if (character.getHasWeapon() == 0)
		std::cout << character.getName() << " has " << character.getNumOfAP() << " AP and is unarmed " << std::endl;
	else if (character.getHasWeapon() == 1)
		std::cout << character.getName() << " has " << character.getNumOfAP() << " AP and wields a " << character.getWeaponName() << std::endl;
	return out;
}