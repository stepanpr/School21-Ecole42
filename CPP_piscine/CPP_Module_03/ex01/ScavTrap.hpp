
#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <string>
#include <iomanip>

class ScavTrap
{
	private:
		int _Hit_points;				//Поинты
		int _Max_hit_points;			//Максимальное количество жизней
		int _Energy_points;				//Очки энергии
		int _Max_energy_points;			//Максимальное количество очков энергии
		int _Level;						//Уровень
		std::string _Name;				//Имя
		int _Melee_attack_damage;		//Урон от атаки в ближнем бою
		int _Ranged_attack_damage;		//Урон от атаки дальнего боя
		int _Armor_damage_reduction;	//Снижение урона брони

		int	_destroyed;
		int _energy_for_vaulthunter;
		std::string _enemy;

	public:
		/* canonical form */
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(ScavTrap const & object);
		ScavTrap &operator=(const ScavTrap& rhs);
		~ScavTrap();
		/* getters */
		int get_Hit_points() const;
		int get_Max_hit_points() const;
		int get_Energy_points() const;
		int get_Max_energy_points() const;
		int get_Level() const;
		std::string get_Name() const;
		int get_Melee_attack_damage() const;
		int get_Ranged_attack_damage() const;
		int get_Armor_damage_reduction() const;
		int get_Destroyed();
		std::string get_Name_of_enemy();
		int get_Energy_for_vaulthunter();

		/* setters */
		void set_Hit_points(int value);
		void set_Max_hit_points(int value);
		void set_Energy_points(int value);
		void set_Max_energy_points(int value);
		void set_Level(int value);
		void set_Name(std::string Name);
		void set_Melee_attack_damage(int value);
		void set_Ranged_attack_damage(int value);
		void set_Armor_damage_reduction(int value);
		void set_Destroyed(int value);
		void set_Name_of_enemy(std::string &enemy);

		/* action-functions */
		void rangedAttack(std::string const & target);			//атака на дистанции (-5 поинтов энергии)
		void meleeAttack(std::string const & target);			//атака "врукопашную" (-10 поинтов энергии)		
		void takeDamage(unsigned int amount);					//полученный урон от противника
		void beRepaired(unsigned int amount);					//восстановление хит-поинтов и поинтов энергии

		/* personal-function */
		void challengeNewcomer(std :: string const & target);    //случайным образом выбирает задачу из набора различных
};

#endif