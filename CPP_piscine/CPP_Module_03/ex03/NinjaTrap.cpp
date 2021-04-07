
#include "NinjaTrap.hpp"

///////* CANONICAL FORM *///////

NinjaTrap::NinjaTrap() : ClapTrap(60, 60, 120, 120, 1, "NoName", 60, 5, 0, 0) 				//дефолтный конструктор								
{																							//запустится конструктор ClapTrap с параметрами
	std::cout << "\e[0;32mNinjaTrap \e[1;32mNoName \e[0;32mis ready 🤖 (default constructor)\e[0m" << std::endl;
}

NinjaTrap::NinjaTrap(std::string Name) : ClapTrap(60, 60, 120, 120, 1, Name, 60, 5, 0, 0)  		//конструктор с параметром
{																								//запустится конструктор ClapTrap с параметрами
	std::cout << "\e[0;32mNinjaTrap \e[1;32m" << this->get_Name() << "\e[0;32m is ready 🤖 (constructor)\e[0m" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & object)													//конструктор копирования
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
	std::cout << "\e[0;32mNinjaTrap \e[1;32m" << this->get_Name() << "\e[0;32m is ready 🤖 (copy constructor)\e[0m" << std::endl;
	// *this = object; //можно использовать этот вариант, 
	//в таком случае поля копировать не нужно - будет запускаться оператор присваивания
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap& rhs)											//оператор присваивания
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
	std::cout << "\e[0;32mNinjaTrap \e[1;32m" << this->get_Name() << " \e[0;32mis ready 🤖 (assignation operator)\e[0m" << std::endl;
	return *this;
}

NinjaTrap::~NinjaTrap()																			//деструктор
{
	std::cout << "\e[0;34mNinjaTrap \e[1;32m" << this->get_Name() << "\e[0;34m is destroyed 💥 (destructor)\e[0m" << std::endl;
}


void NinjaTrap::ninjaShoebox(FragTrap &frend)
{
	std::cout << " 🤖💬 \e[0;32m\"Dont't touch him!\"\e[0;36m say friend \e[1;32m" << frend.get_Name() << "\e[0m" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &frend)
{
	std::cout << " 🤖💬 \e[0;32m\"Dont't touch him!\"\e[0;36m say friend \e[1;32m" << frend.get_Name() << "\e[0m" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &frend)
{
	std::cout << " 🤖💬 \e[0;32m\"Dont't touch him!\"\e[0;36m say friend \e[1;32m" << frend.get_Name() << "\e[0m" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &frend)
{
	std::cout << " 🤖💬 \e[0;32m\"Dont't touch him!\"\e[0;36m say friend \e[1;32m" << frend.get_Name() << "\e[0m" << std::endl;
}
