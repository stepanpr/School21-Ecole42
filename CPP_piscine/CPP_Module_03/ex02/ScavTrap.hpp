
#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <string>
#include <iomanip>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		/* canonical form */
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(ScavTrap const & object);
		ScavTrap &operator=(const ScavTrap& rhs);
		~ScavTrap();
		/* personal-function */
		void challengeNewcomer(std :: string const & target);    //случайным образом выбирает задачу из набора различных
};

#endif