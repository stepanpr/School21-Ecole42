
#include "FragTrap.hpp"

///////* CANONICAL FORM *///////
FragTrap::FragTrap() //: ClapTrap(100, 100, 100, 100, 1, "NoName", 30, 20, 5, 0)					//дефолтный конструктор						
{																									//запустится дефолтный конструктор ClapTrap
	this->set_Hit_points(100);
	this->set_Max_hit_points(100);
	this->set_Energy_points(100);
	this->set_Max_energy_points(100);
	this->set_Level(1);
	this->set_Name("NoName");
	this->set_Melee_attack_damage(30);
	this->set_Ranged_attack_damage(20);
	this->set_Armor_damage_reduction(5);
	this->set_Destroyed(0);

	this->set_Energy_for_vaulthunter(1);

	std::cout << "\e[0;32mFR4G-TP \e[1;32mNoName \e[0;32mis ready 🤖 (default constructor)\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string Name) // : ClapTrap(100, 100, 100, 100, 1, Name, 30, 20, 5, 0)       //конструктор с параметром
{																									//запустится дефолтный конструктор ClapTrap
	this->set_Hit_points(100);
	this->set_Max_hit_points(100);
	this->set_Energy_points(100);
	this->set_Max_energy_points(100);
	this->set_Level(1);
	this->set_Name(Name);
	this->set_Melee_attack_damage(30);
	this->set_Ranged_attack_damage(20);
	this->set_Armor_damage_reduction(5);
	this->set_Destroyed(0);

	this->set_Energy_for_vaulthunter(1);

	std::cout << "\e[0;32mFR4G-TP \e[1;32m" << this->get_Name() << "\e[0;32m is ready 🤖 (constructor)\e[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const & object)															//конструктор копирования
{
	std::string nameOfCopy = "CopyOf" + object.get_Name();
	this->set_Hit_points(object.get_Hit_points());
	this->set_Max_hit_points(object.get_Max_hit_points());
	this->set_Energy_points(object.get_Energy_points());
	this->set_Max_energy_points(object.get_Max_energy_points());
	this->set_Level(object.get_Level());
	this->set_Name(nameOfCopy);
	this->set_Melee_attack_damage(object.get_Melee_attack_damage());
	this->set_Ranged_attack_damage(object.get_Ranged_attack_damage());
	this->set_Armor_damage_reduction(object.get_Armor_damage_reduction());
	this->set_Destroyed(0);
	std::cout << "\e[0;32mFR4G-TP \e[1;32m" << this->get_Name() << "\e[0;32m is ready 🤖 (copy constructor)\e[0m" << std::endl;

	// *this = object; //можно использовать этот вариант, 
	//в таком случае поля копировать не нужно - будет запускаться оператор присваивания
}

FragTrap &FragTrap::operator=(const FragTrap& rhs)													//оператор присваивания
{
	std::string nameOfCopy = "CopyOf" + rhs.get_Name();
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

	std::cout << "\e[0;32mFR4G-TP \e[1;32m" << this->get_Name() << " \e[0;32mis ready 🤖 (assignation operator)\e[0m" << std::endl;
	return *this;
}

FragTrap::~FragTrap()																			//деструктор
{
	std::cout << "\e[0;34mFR4G-TP \e[1;32m" << this->get_Name() << "\e[0;34m is destroyed 💥 (destructor)\e[0m" << std::endl;
}


///////* GETTERS *///////
int FragTrap::get_Energy_for_vaulthunter() { return this->_energy_for_vaulthunter; }

///////* SETTERS *///////
void FragTrap::set_Energy_for_vaulthunter(int value) { this->_energy_for_vaulthunter = value; }


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
