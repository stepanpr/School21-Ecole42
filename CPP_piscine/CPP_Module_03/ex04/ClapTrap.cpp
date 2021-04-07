/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 08:57:49 by emabel            #+#    #+#             */
/*   Updated: 2021/03/15 10:12:01 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

///////* CANONICAL FORM *///////
ClapTrap::ClapTrap() 																			//дефолтный конструктор	
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(int hit_point, int max_hit_point, int energy_points, 						//конструктор с параметрами
int max_energy_points, int level, std::string name,
int melee_damage, int ranged_attack_damage, int armor_damage, int destroyed)
{
	this->set_Hit_points(hit_point);
	this->set_Max_hit_points(max_hit_point);
	this->set_Energy_points(energy_points);
	this->set_Max_energy_points(max_energy_points);
	this->set_Level(level);
	this->set_Name(name);
	this->set_Melee_attack_damage(melee_damage);
	this->set_Ranged_attack_damage(ranged_attack_damage);
	this->set_Armor_damage_reduction(armor_damage);
	this->set_Destroyed(destroyed);
	std::cout << "ClapTrap parametric constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & object)														//конструктор копирования
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	*this = object;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& rhs)												//оператор присваивания
{
	std::string nameOfCopy = "CopyOf" + rhs._Name;
	this->set_Hit_points(rhs.get_Hit_points());
	this->set_Max_hit_points(rhs.get_Max_hit_points());
	this->set_Energy_points(rhs.get_Energy_points());
	this->set_Max_energy_points(rhs.get_Max_energy_points());
	this->set_Level(rhs.get_Level());
	this->set_Name(nameOfCopy);
	this->set_Melee_attack_damage(rhs.get_Melee_attack_damage());
	this->set_Ranged_attack_damage(rhs.get_Ranged_attack_damage());
	this->set_Armor_damage_reduction(rhs.get_Armor_damage_reduction());
	this->set_Destroyed(0);
	return *this;
}

ClapTrap::~ClapTrap()																			//деструктор
{
    std::cout << "ClapTrap destructor" << std::endl;
}




///////* GETTERS *///////
int ClapTrap::get_Hit_points() const { return this->_Hit_points; }
int ClapTrap::get_Max_hit_points() const { return this->_Max_hit_points; }
int ClapTrap::get_Energy_points() const { return this->_Energy_points; }
int ClapTrap::get_Max_energy_points() const { return this->_Max_energy_points; }
int ClapTrap::get_Level() const { return this->_Level; }
std::string ClapTrap::get_Name() const { return this->_Name; }
int ClapTrap::get_Melee_attack_damage() const { return this->_Melee_attack_damage; }
int ClapTrap::get_Ranged_attack_damage() const { return this->_Ranged_attack_damage; }
int ClapTrap::get_Armor_damage_reduction() const { return this->_Armor_damage_reduction; }

int ClapTrap::get_Destroyed() { return this->_destroyed; }
std::string ClapTrap::get_Name_of_enemy() {return this->_enemy; }




///////* SETTERS *///////
void ClapTrap::set_Hit_points(int value) { this->_Hit_points = value; }
void ClapTrap::set_Max_hit_points(int value) { this->_Max_hit_points = value; }
void ClapTrap::set_Energy_points(int value) { this->_Energy_points = value; }
void ClapTrap::set_Max_energy_points(int value) { this->_Max_energy_points = value; }
void ClapTrap::set_Level(int value) { this->_Level = value; }
void ClapTrap::set_Name(std::string Name) { this->_Name = Name; }
void ClapTrap::set_Melee_attack_damage(int value) { this->_Melee_attack_damage = value; }
void ClapTrap::set_Ranged_attack_damage(int value) { this->_Ranged_attack_damage = value; }
void ClapTrap::set_Armor_damage_reduction(int value) { this->_Armor_damage_reduction = value; }

void ClapTrap::set_Destroyed(int value) { this->_destroyed = value; }
void ClapTrap::set_Name_of_enemy(std::string &enemy) { this->_enemy = enemy; }




///////* ACTION-FUNCTIONS *///////
void ClapTrap::rangedAttack(std::string const & target)									//атака на дистанции (-5 поинтов энергии)
{
	if (this->get_Energy_points() < 5)
	{
		std::cout << "\e[0;31m!Not enough energy points to fire, use the recovery station\e[0m" << std::endl;
		return;
	}
	this->set_Energy_points(this->get_Energy_points() - 5);
	std::cout << " 🏹 \e[0;36mClapTrap \e[1;32m" << this->get_Name() << "\e[0;36m attacks \e[1;35m"
	<< target << "\e[0;36m at range, causing \e[0;37m" << this->get_Ranged_attack_damage() 
	<< "\e[0;36m points of damage! (\e[0;37m" << this->get_Energy_points() 
	<< "\e[0;36m points of energy left)\e[0m" 
	<< std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)									//атака "врукопашную" (-10 поинтов энергии)
{
	if (this->get_Energy_points() < 10)
	{
		std::cout << "\e[0;31m!Not enough energy points for melee combat, use the recovery station\e[0m" << std::endl;
		return;
	}
	this->set_Energy_points(this->get_Energy_points() - 10);
	std::cout << " 🥊 \e[0;36mClapTrap \e[1;32m" << this->get_Name() << "\e[0;36m attacks \e[1;35m"
	<< target << "\e[0;36m at melee, causing \e[0;37m" << this->get_Melee_attack_damage() 
	<< "\e[0;36m points of damage! (\e[0;37m" << this->get_Energy_points() << "\e[0;36m points of energy left)\e[0m" 
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)											//полученный урон от противника
{
	if((unsigned int)this->get_Armor_damage_reduction() > amount)
	{
		std::cout << "\e[0;36m 🛡 Your armor this time protected from damage of \e[1;35m" << this->get_Name_of_enemy() << "\e[0;36m !\e[0m" << std::endl;
		return;
	} 
	else
		amount -= this->get_Armor_damage_reduction();
	if (this->get_Hit_points() < 0)
		this->set_Hit_points(0);
	if ((amount >= (unsigned int)this->get_Hit_points()))
	{
		this->set_Destroyed(1);
		return;
	}
	this->set_Hit_points(this->get_Hit_points() - amount);
	std::cout << " 🔫 \e[0;31mDanger! \e[0;36mClapTrap \e[1;32m" << this->get_Name() 
	<< "\e[0;36m takes \e[0;37m"<< amount << "\e[0;36m points of damage from \e[1;35m" << this->get_Name_of_enemy() << "\e[0;36m! (\e[0;37m" 
	<< this->get_Hit_points() << "\e[0;36m hit points left)\e[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)											//восстановление хит-поинтов и поинтов энергии
{
	this->set_Hit_points(this->get_Hit_points() + amount);
	if (this->get_Hit_points() > this->get_Max_hit_points())
		this->set_Hit_points(this->get_Max_hit_points());
	this->set_Energy_points(this->get_Energy_points() + amount);
	if (this->get_Energy_points() > this->get_Max_energy_points())
		this->set_Energy_points(this->get_Max_energy_points());
	std::cout << " 💬 \e[0;36mGreat! Now \e[1;32m" << this->get_Name() 
	<< "\e[0;36m has \e[0;37m" << this->get_Hit_points() 
	<< "\e[0;36m hit points and \e[0;37m " << this->get_Energy_points() << "\e[0;36m energy points!\e[0m ✅" << std::endl;
}
