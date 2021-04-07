


#ifndef	FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>

class FragTrap
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
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(FragTrap const & object);
		FragTrap &operator=(const FragTrap& rhs);
		~FragTrap();
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
		void set_Energy_for_vaulthunter(int value);

		/* action-functions */
		void rangedAttack(std::string const & target);			//атака на дистанции (-5 поинтов энергии)
		void meleeAttack(std::string const & target);			//атака "врукопашную" (-10 поинтов энергии)		
		void takeDamage(unsigned int amount);					//полученный урон от противника
		void beRepaired(unsigned int amount);					//восстановление хит-поинтов и поинтов энергии
		void vaulthunter_dot_exe(std :: string const & target); //атака случайная (5 способов; -25 поинтов энергии)
};

#endif

// Завершите, добавив функцию vaulthunter_dot_exe 
// (std :: string const & target), которая произведет 
// полуслучайную атаку на цель. Сделайте так, чтобы каждый 
// раз, когда он вызывается, он выбирает (предпочтительно) 
// забавную атаку, выбранную случайным образом из пула, 
// по крайней мере, 5 возможных атак. Что бы вы ни хотели 
// использовать для этого, это нормально, но, как обычно, 
// чем элегантнее ваш метод, тем лучше. Выполнение этой функции 
// стоит 25 очков энергии. Если у вас недостаточно энергии, 
// он ничего не сделает, кроме как напечатать что-нибудь, 
// указывающее, что у него закончилась энергия.