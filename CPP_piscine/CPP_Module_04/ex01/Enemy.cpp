
#include "Enemy.hpp"

//==================================CANONIC=FORM===============================

Enemy::Enemy(){}

Enemy::Enemy(int hp, std::string const & type) : _HP(hp), _Type(type){}


Enemy::Enemy(Enemy const & src)
{
	*this = src;
}
Enemy &Enemy::operator= (const Enemy& rhs)
{
	if (this != &rhs)
	{
		this->_HP = rhs._HP;
		this->_Type = rhs._Type;
	}
	return (*this);
}	

Enemy::~Enemy(){}


//====================================GETTERS===================================

std::string const Enemy::getType() const { return this->_Type; }
int Enemy::getHP() const { return this->_HP; }

//====================================SETTERS===================================

void Enemy::setHP(int value) { this->_HP = value; }
void Enemy::setType(std::string type) { this->_Type = type; }

//====================================ACTIONS===================================


void Enemy::takeDamage(int damage)
{
	if (damage <= 0)
		return ;
	if (this->_HP - damage <= 0)
		this->_HP = 0;
	else
		this->setHP(this->getHP() - damage);
	if (getHP() <= 0)
		delete this;
	return ;
}
