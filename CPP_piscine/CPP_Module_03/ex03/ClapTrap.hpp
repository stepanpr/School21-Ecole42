




#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>
#include <iomanip>

class ClapTrap
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
		std::string _enemy;

	public:
		/* canonical form */
		ClapTrap();
		// ClapTrap(std::string name);
		ClapTrap(int hit_point, int max_hit_point, int energy_points,
        int max_energy_points, int level, std::string name,
        int melee_damage, int ranged_attack_damage, int armor_damage, int destroyed);
		ClapTrap(ClapTrap const & object);
		ClapTrap &operator=(ClapTrap const & rhs);
		 ~ClapTrap();

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

};

#endif


// class ClapTrap
// {
// protected:
// 	int			Hit_points;
// 	int			Max_Hit_points;
// 	int			Energy_points;
// 	int			Max_energy_potins;
// 	int			Level;
// 	std::string name;
// 	int			Melee_attack_damage;
// 	int			Ranged_attack_damage;
// 	int			Armor_damage_reduction;
// public:
// 	void		rangedAttack(std::string const& target);
// 	void		meleeAttack(std::string const& target);
// 	bool		takeDamage(unsigned int amount);
// 	void		beRepaired(unsigned int amount);
// 	ClapTrap(void);
// 	ClapTrap(std::string name);
// 	ClapTrap(ClapTrap const &f);
// 	ClapTrap &operator=(ClapTrap const &f);
// 	~ClapTrap(void);
// };

// #endif

// class ClapTrap
// {
// protected:
// 	int			Hit_points;
// 	int			Max_Hit_points;
// 	int			Energy_points;
// 	int			Max_energy_potins;
// 	int			Level;
// 	std::string name;
// 	int			Melee_attack_damage;
// 	int			Ranged_attack_damage;
// 	int			Armor_damage_reduction;
// public:
// 	void		rangedAttack(std::string const& target);
// 	void		meleeAttack(std::string const& target);
// 	bool		takeDamage(unsigned int amount);
// 	void		beRepaired(unsigned int amount);
// 	ClapTrap(void);
// 	ClapTrap(std::string name);
// 	ClapTrap(ClapTrap const &f);
// 	ClapTrap &operator=(ClapTrap const &f);
// 	~ClapTrap(void);
// };