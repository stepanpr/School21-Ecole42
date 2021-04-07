#include "ScavTrap.hpp"

///////* CANONICAL FORM *///////

ScavTrap::ScavTrap() : ClapTrap(100, 100, 50, 50, 1, "NoName", 20, 15, 3, 0) 				//дефолтный конструктор								
{																							//запустится конструктор ClapTrap с параметрами
	// this->set_Hit_points(100);
	// this->set_Max_hit_points(100);
	// this->set_Energy_points(50);
	// this->set_Max_energy_points(50);
	// this->set_Level(1);
	// this->set_Name("NoName");
	// this->set_Melee_attack_damage(20);
	// this->set_Ranged_attack_damage(15);
	// this->set_Armor_damage_reduction(3);
	// this->set_Destroyed(0);
	std::cout << "\e[0;32mCL4P-TP \e[1;32mNoName \e[0;32mis ready 🤖 (default constructor)\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(100, 100, 50, 50, 1, Name, 20, 15, 3, 0) 		//конструктор с параметром
{																								//запустится конструктор ClapTrap с параметрами
	// this->set_Hit_points(100);
	// this->set_Max_hit_points(100);
	// this->set_Energy_points(50);
	// this->set_Max_energy_points(50);
	// this->set_Level(1);
	// this->set_Name("NoName");
	// this->set_Melee_attack_damage(20);
	// this->set_Ranged_attack_damage(15);
	// this->set_Armor_damage_reduction(3);
	// this->set_Destroyed(0);
	std::cout << "\e[0;32mCL4P-TP \e[1;32m" << this->get_Name() << "\e[0;32m is ready 🤖 (constructor)\e[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & object)													//конструктор копирования
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
	std::cout << "\e[0;32mCL4P-TP \e[1;32m" << this->get_Name() << "\e[0;32m is ready 🤖 (copy constructor)\e[0m" << std::endl;
	// *this = object; //можно использовать этот вариант, 
	//в таком случае поля копировать не нужно - будет запускаться оператор присваивания
}

ScavTrap &ScavTrap::operator=(const ScavTrap& rhs)											//оператор присваивания
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
	std::cout << "\e[0;32mCL4P-TP \e[1;32m" << this->get_Name() << " \e[0;32mis ready 🤖 (assignation operator)\e[0m" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()																			//деструктор
{
	std::cout << "\e[0;34mCL4P-TP \e[1;32m" << this->get_Name() << "\e[0;34m is destroyed 💥 (destructor)\e[0m" << std::endl;
}




///////* PERSONAL-FUNCTION *///////
void ScavTrap::challengeNewcomer(std :: string const & target)									//способность
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
	// std::string weapons[5] = {"Сlimatic weapon 🌋", "Superweapon 🦸‍♂️", "Petard 🧨", "Wrench 🔧", "Broom 🧹"};

	// if (this->get_Energy_points() >= 25)
	// {
		// this->set_Energy_for_vaulthunter(1);
		// this->set_Energy_points(this->get_Energy_points() - 25);

		std::cout << " \e[0;36m ...suddenly \e[1;32m" << this->get_Name() << "\e[0;36m shouts out 🤖💬: \e[0;32m" 
		<< quotes[(long)this % 10] << std::endl << "\e[0;36m ...and jumping around \e[1;35m" << target
		<< "\e[0;36m...\e[0m" << std::endl;

	// 	std::cout << " \e[0;36m ...suddenly \e[1;32m" << this->get_Name() << "\e[0;36m says 🤖💬: \e[0;32m" 
	// 	<< quotes[(long)this % 10] << std::endl << "\e[0;36m ...and attacks a \e[1;35m" << this->get_Name_of_enemy() 
	// 	<< "\e[0;36m with its \e[1;36m" << weapons[(long)this % 5] << "\e[0;36m dealing a \e[0;37m"
	// 	<< 50 + (long)this % 50 << "\e[0;36m of damage to the enemy! (\e[0;37m" << this->get_Energy_points() 
	// 	<< "\e[0;36m points of energy left)\e[0m" << std::endl;
	// }
	// else
	// 	this->set_Energy_for_vaulthunter(0);
	return;
}