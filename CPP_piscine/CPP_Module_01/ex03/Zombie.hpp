
//
// CPP_Mod01_ex03/21school/emabel
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
	Zombie(void);
	~Zombie(void);
	void announce();			//показать зомби

	void setName(std::string name);
	void setType(std::string type);
};

#endif