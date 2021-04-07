#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _Hit_points(100), _Max_hit_points(100), _Energy_points(50),						    //дефолтный конструктор	
_Max_energy_points(50),  _Level(1), _Melee_attack_damage(20), _Ranged_attack_damage(15), 
_Armor_damage_reduction(3), _destroyed(0)										
{
	std::cout << "\e[0;32mCL4P-TP \e[1;32mNoName \e[0;32mis ready 🤖 (default constructor)\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : _Hit_points(100), _Max_hit_points(100), _Energy_points(50),		//конструктор с параметром
_Max_energy_points(50), _Level(1), _Name(Name), _Melee_attack_damage(20), _Ranged_attack_damage(15),
_Armor_damage_reduction(3), _destroyed(0)
{
	std::cout << "\e[0;32mCL4P-TP \e[1;32m" << this->_Name << "\e[0;32m is ready 🤖 (constructor)\e[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & object)															//конструктор копирования
{
	*this = object;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& rhs)												//конструктор копирования
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

	std::cout << "\e[0;32mCL4P-TP \e[1;32m" << this->_Name << " \e[0;32mis ready 🤖 (assignation operator)\e[0m" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()																			//деструктор
{
	std::cout << "\e[0;34mCL4P-TP \e[1;32m" << this->_Name << "\e[0;34m is destroyed 💥 (destructor)\e[0m" << std::endl;
}

///////* GETTERS *///////

int ScavTrap::get_Hit_points() const { return this->_Hit_points; }
int ScavTrap::get_Max_hit_points() const { return this->_Max_hit_points; }
int ScavTrap::get_Energy_points() const { return this->_Energy_points; }
int ScavTrap::get_Max_energy_points() const { return this->_Max_energy_points; }
int ScavTrap::get_Level() const { return this->_Level; }
std::string ScavTrap::get_Name() const { return this->_Name; }
int ScavTrap::get_Melee_attack_damage() const { return this->_Melee_attack_damage; }
int ScavTrap::get_Ranged_attack_damage() const { return this->_Ranged_attack_damage; }
int ScavTrap::get_Armor_damage_reduction() const { return this->_Armor_damage_reduction; }
int ScavTrap::get_Destroyed() { return this->_destroyed; }
std::string ScavTrap::get_Name_of_enemy() {return this->_enemy; }


///////* SETTERS *///////

void ScavTrap::set_Hit_points(int value) { this->_Hit_points = value; }
void ScavTrap::set_Max_hit_points(int value) { this->_Max_hit_points = value; }
void ScavTrap::set_Energy_points(int value) { this->_Energy_points = value; }
void ScavTrap::set_Max_energy_points(int value) { this->_Max_energy_points = value; }
void ScavTrap::set_Level(int value) { this->_Level = value; }
void ScavTrap::set_Name(std::string Name) { this->_Name = Name; }
void ScavTrap::set_Melee_attack_damage(int value) { this->_Melee_attack_damage = value; }
void ScavTrap::set_Ranged_attack_damage(int value) { this->_Ranged_attack_damage = value; }
void ScavTrap::set_Armor_damage_reduction(int value) { this->_Armor_damage_reduction = value; }
void ScavTrap::set_Destroyed(int value) { this->_destroyed = value; }
void ScavTrap::set_Name_of_enemy(std::string &enemy) { this->_enemy = enemy; }


///////* ACTION-FUNCTIONS *///////

void ScavTrap::rangedAttack(std::string const & target)									//атака на дистанции (-5 поинтов энергии)
{
	if (this->get_Energy_points() < 5)
	{
		std::cout << "\e[0;31m!Not enough energy points to fire, use the recovery station\e[0m" << std::endl;
		return;
	}
	this->set_Energy_points(this->get_Energy_points() - 5);
	std::cout << " 🏹 \e[0;36mCL4G-TP \e[1;32m" << this->get_Name() << "\e[0;36m attacks \e[1;35m"
	<< target << "\e[0;36m at range, causing \e[0;37m" << this->get_Ranged_attack_damage() 
	<< "\e[0;36m points of damage! (\e[0;37m" << this->get_Energy_points() 
	<< "\e[0;36m points of energy left)\e[0m" 
	<< std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)									//атака "врукопашную" (-10 поинтов энергии)
{
	if (this->get_Energy_points() < 10)
	{
		std::cout << "\e[0;31m!Not enough energy points for melee combat, use the recovery station\e[0m" << std::endl;
		return;
	}
	this->set_Energy_points(this->get_Energy_points() - 10);
	std::cout << " 🥊 \e[0;36mCL4G-TP \e[1;32m" << this->get_Name() << "\e[0;36m attacks \e[1;35m"
	<< target << "\e[0;36m at melee, causing \e[0;37m" << this->get_Melee_attack_damage() 
	<< "\e[0;36m points of damage! (\e[0;37m" << this->get_Energy_points() << "\e[0;36m points of energy left)\e[0m" 
	<< std::endl;
}




void ScavTrap::takeDamage(unsigned int amount)											//полученный урон от противника
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
	std::cout << " 🔫 \e[0;31mDanger! \e[0;36mCL4G-TP \e[1;32m" << this->get_Name() 
	<< "\e[0;36m takes \e[0;37m"<< amount << "\e[0;36m points of damage from \e[1;35m" << this->get_Name_of_enemy() << "\e[0;36m! (\e[0;37m" 
	<< this->get_Hit_points() << "\e[0;36m hit points left)\e[0m" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)											//восстановление хит-поинтов и поинтов энергии
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

void ScavTrap::challengeNewcomer(std :: string const & target)						//способность
{
	std::string quotes[10] = {	"\"So... does this make me your favorite?\"",
							"\"What are YOU doing down here?\"",
							"\"This is no time to be lazy!\"",
							"\"You love me, right?\"",
							"\"You, me... keeping on... together?\"",
							"\"You can thank me later!\"",
							"\"Wait, this isn't vegetable juice!\"",
							"\"I'm a mean, green, acid machine!\"",
							"\"Sip-a-green! Zzzz!\"",
							"\"Something eating you?\"" };
	std::cout << " \e[0;36m ...suddenly \e[1;32m" << this->get_Name() << "\e[0;36m shouts out 🤖💬: \e[0;32m" 
	<< quotes[(long)this % 10] << std::endl << "\e[0;36m ...and jumping around \e[1;35m" << target
	<< "\e[0;36m...\e[0m" << std::endl;
	return;
}