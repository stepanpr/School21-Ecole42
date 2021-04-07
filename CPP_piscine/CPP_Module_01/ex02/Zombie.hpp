
//
// CPP_Mod01_ex02/21school/emabel
//

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Zombie
{
private:
	std::string name;			//имя зомби
	std::string type;			// 1-4
public:
	Zombie(std::string name, std::string type);
	~Zombie();
	void announce();			//показать зомби
};

#endif