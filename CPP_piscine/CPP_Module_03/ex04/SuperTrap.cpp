
#include "SuperTrap.hpp"

///////* CANONICAL FORM *///////

SuperTrap::SuperTrap()										  									//дефолтный конструктор								
{	
	FragTrap::set_Hit_points(100);
	FragTrap::set_Max_hit_points(100);
	NinjaTrap::set_Energy_points(120);
	NinjaTrap::set_Max_energy_points(120);
	FragTrap::set_Level(1);
	FragTrap::set_Name("Name");
	NinjaTrap::set_Melee_attack_damage(60);
	FragTrap::set_Ranged_attack_damage(20);
	FragTrap::set_Armor_damage_reduction(5);
	std::cout << "\e[0;32mSuperTrap \e[1;32mNoName \e[0;32mis ready 🤖 (default constructor)\e[0m" << std::endl;
}

SuperTrap::SuperTrap(std::string const &Name)														//конструктор с параметром
{																									
	FragTrap::set_Hit_points(100);
	FragTrap::set_Max_hit_points(100);
	NinjaTrap::set_Energy_points(120);
	NinjaTrap::set_Max_energy_points(120);
	FragTrap::set_Level(1);
	FragTrap::set_Name(Name);
	NinjaTrap::set_Melee_attack_damage(60);
	FragTrap::set_Ranged_attack_damage(20);
	FragTrap::set_Armor_damage_reduction(5);
	std::cout << "\e[0;32mSuperTrap \e[1;32m" << FragTrap::get_Name()  << "\e[0;32m is ready 🤖 (constructor)\e[0m" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & object)															//конструктор копирования
{
	std::cout << "\e[0;32mSuperTrap \e[1;32m" << FragTrap::get_Name() << "\e[0;32m in construction 🤖 (copy constructor)\e[0m" << std::endl;
	*this = object;
}

SuperTrap &SuperTrap::operator=(const SuperTrap& rhs)									 				//оператор присваивания
{
	std::string nameOfCopy = "CopyOf" + rhs.FragTrap::get_Name();
	FragTrap::set_Hit_points(rhs.FragTrap::get_Hit_points());
	FragTrap::set_Max_hit_points(rhs.FragTrap::get_Max_hit_points());
	FragTrap::set_Energy_points(rhs.FragTrap::get_Energy_points());
	FragTrap::set_Max_energy_points(rhs.FragTrap::get_Max_energy_points());
	FragTrap::set_Level(rhs.FragTrap::get_Level());
	FragTrap::set_Name(nameOfCopy);
	FragTrap::set_Melee_attack_damage(rhs.FragTrap::get_Melee_attack_damage());
	FragTrap::set_Ranged_attack_damage(rhs.FragTrap::get_Ranged_attack_damage());
	FragTrap::set_Armor_damage_reduction(rhs.FragTrap::get_Armor_damage_reduction());
	FragTrap::set_Destroyed(0);
	std::cout << "\e[0;32mSuperTrap \e[1;32m" << FragTrap::get_Name() << " \e[0;32mis ready 🤖 (assignation operator)\e[0m" << std::endl;
	return *this;
}

SuperTrap::~SuperTrap()																						//деструктор
{
	std::cout << "\e[0;34mSuperTrap \e[1;32m" << FragTrap::get_Name() << "\e[0;34m is destroyed 💥 (destructor)\e[0m" << std::endl;
}



void		SuperTrap::rangedAttack(std::string const& target)
{
    FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const& target)
{
    NinjaTrap::meleeAttack(target);
}
