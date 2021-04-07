
#include "FragTrap.hpp"

///////* CANONICAL FORM *///////

FragTrap::FragTrap() 																		//дефолтный конструктор						
{
	this->set_Hit_points(100);
	this->set_Max_hit_points(100);
	this->set_Energy_points(100);
	this->set_Max_energy_points(100);
	this->set_Level(1);
	this->set_Name("NoName");
	this->set_Melee_attack_damage(30);
	this->set_Ranged_attack_damage(20);
	this->set_Armor_damage_reduction(5);

	this->set_Energy_for_vaulthunter(1);
	this->set_Destroyed(0);

	std::cout << "\e[0;32mFR4G-TP \e[1;32mNoName \e[0;32mis ready 🤖 (default constructor)\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string Name) : _Hit_points(100), _Max_hit_points(100), _Energy_points(100),		//конструктор с параметром
_Max_energy_points(100), _Level(1), _Name(Name), _Melee_attack_damage(30), _Ranged_attack_damage(20),
_Armor_damage_reduction(5), _destroyed(0), _energy_for_vaulthunter(1)
{
	std::cout << "\e[0;32mFR4G-TP \e[1;32m" << this->_Name << "\e[0;32m is ready 🤖 (constructor)\e[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const & object)															//конструктор копирования
{
	*this = object;
}

FragTrap &FragTrap::operator=(const FragTrap& rhs)												//конструктор копирования
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

	std::cout << "\e[0;32mFR4G-TP \e[1;32m" << this->_Name << " \e[0;32mis ready 🤖 (assignation operator)\e[0m" << std::endl;
	return *this;
}

FragTrap::~FragTrap()																			//деструктор
{
	std::cout << "\e[0;34mFR4G-TP \e[1;32m" << this->_Name << "\e[0;34m is destroyed 💥 (destructor)\e[0m" << std::endl;
}


///////* GETTERS *///////

int FragTrap::get_Hit_points() const { return this->_Hit_points; }
int FragTrap::get_Max_hit_points() const { return this->_Max_hit_points; }
int FragTrap::get_Energy_points() const { return this->_Energy_points; }
int FragTrap::get_Max_energy_points() const { return this->_Max_energy_points; }
int FragTrap::get_Level() const { return this->_Level; }
std::string FragTrap::get_Name() const { return this->_Name; }
int FragTrap::get_Melee_attack_damage() const { return this->_Melee_attack_damage; }
int FragTrap::get_Ranged_attack_damage() const { return this->_Ranged_attack_damage; }
int FragTrap::get_Armor_damage_reduction() const { return this->_Armor_damage_reduction; }

int FragTrap::get_Destroyed() { return this->_destroyed; }
std::string FragTrap::get_Name_of_enemy() {return this->_enemy; }
int FragTrap::get_Energy_for_vaulthunter() { return this->_energy_for_vaulthunter; }



///////* SETTERS *///////

void FragTrap::set_Hit_points(int value) { this->_Hit_points = value; }
void FragTrap::set_Max_hit_points(int value) { this->_Max_hit_points = value; }
void FragTrap::set_Energy_points(int value) { this->_Energy_points = value; }
void FragTrap::set_Max_energy_points(int value) { this->_Max_energy_points = value; }
void FragTrap::set_Level(int value) { this->_Level = value; }
void FragTrap::set_Name(std::string Name) { this->_Name = Name; }
void FragTrap::set_Melee_attack_damage(int value) { this->_Melee_attack_damage = value; }
void FragTrap::set_Ranged_attack_damage(int value) { this->_Ranged_attack_damage = value; }
void FragTrap::set_Armor_damage_reduction(int value) { this->_Armor_damage_reduction = value; }

void FragTrap::set_Destroyed(int value) { this->_destroyed = value; }
void FragTrap::set_Name_of_enemy(std::string &enemy) { this->_enemy = enemy; }
void FragTrap::set_Energy_for_vaulthunter(int value) { this->_energy_for_vaulthunter = value; }



///////* ACTION-FUNCTIONS *///////

void FragTrap::rangedAttack(std::string const & target)									//атака на дистанции (-5 поинтов энергии)
{
	if (this->get_Energy_points() < 5)
	{
		std::cout << "\e[0;31m!Not enough energy points to fire, use the recovery station\e[0m" << std::endl;
		return;
	}
	this->set_Energy_points(this->get_Energy_points() - 5);
	std::cout << " 🏹 \e[0;36mFR4G-TP \e[1;32m" << this->get_Name() << "\e[0;36m attacks \e[1;35m"
	<< target << "\e[0;36m at range, causing \e[0;37m" << this->get_Ranged_attack_damage() 
	<< "\e[0;36m points of damage! (\e[0;37m" << this->get_Energy_points() 
	<< "\e[0;36m points of energy left)\e[0m" 
	<< std::endl;
}

void FragTrap::meleeAttack(std::string const & target)									//атака "врукопашную" (-10 поинтов энергии)
{
	if (this->get_Energy_points() < 10)
	{
		std::cout << "\e[0;31m!Not enough energy points for melee combat, use the recovery station\e[0m" << std::endl;
		return;
	}
	this->set_Energy_points(this->get_Energy_points() - 10);
	std::cout << " 🥊 \e[0;36mFR4G-TP \e[1;32m" << this->get_Name() << "\e[0;36m attacks \e[1;35m"
	<< target << "\e[0;36m at melee, causing \e[0;37m" << this->get_Melee_attack_damage() 
	<< "\e[0;36m points of damage! (\e[0;37m" << this->get_Energy_points() << "\e[0;36m points of energy left)\e[0m" 
	<< std::endl;
}


void FragTrap::takeDamage(unsigned int amount)											//полученный урон от противника
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
	std::cout << " 🔫 \e[0;31mDanger! \e[0;36mFR4G-TP \e[1;32m" << this->get_Name() 
	<< "\e[0;36m takes \e[0;37m"<< amount << "\e[0;36m points of damage from \e[1;35m" << this->get_Name_of_enemy() << "\e[0;36m! (\e[0;37m" 
	<< this->get_Hit_points() << "\e[0;36m hit points left)\e[0m" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)											//восстановление хит-поинтов и поинтов энергии
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




///////* PERSONAL-FUNCTION *///////

void FragTrap::vaulthunter_dot_exe(std :: string const & target)						//атака случайная (5 способов; -25 поинтов энергии)
{
	std::string quotes[10] = {	"\"There's more to learn!\"",
							"\"Let me teach you the ways of magic!\"",
							"\"I got quests!\"",
							"\"Magic waits for no one, apprentice!\"",
							"\"Still working on that quest?\"",
							"\"Shouldn't you be murdering something about now?\"",
							"\"No way! That's, like, my third favorite kind of magic!\"",
							"\"Hey! You're TALKING to me! And I didn't even have an exclamation point over my head! This is the BEST day of my life!\"",
							"\"Sooooo... how are things?\"",
							"\"Hey, best friend!\"" };
	std::string weapons[5] = {"Сlimatic weapon 🌋", "Superweapon 🦸‍♂️", "Petard 🧨", "Wrench 🔧", "Broom 🧹"};

	if (this->get_Energy_points() >= 25)
	{
		this->set_Energy_for_vaulthunter(1);
		this->set_Energy_points(this->get_Energy_points() - 25);
		std::cout << " \e[0;36m ...suddenly \e[1;32m" << this->get_Name() << "\e[0;36m says 🤖💬: \e[0;32m" 
		<< quotes[(long)this % 10] << std::endl << "\e[0;36m ...and attacks a \e[1;35m" << target 
		<< "\e[0;36m with its \e[1;36m" << weapons[(long)this % 5] << "\e[0;36m dealing a \e[0;37m"
		<< 50 + (long)this % 50 << "\e[0;36m of damage to the enemy! (\e[0;37m" << this->get_Energy_points() 
		<< "\e[0;36m points of energy left)\e[0m" << std::endl;
	}
	else
		this->set_Energy_for_vaulthunter(0);
	return;
}
