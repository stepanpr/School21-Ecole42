


#ifndef	FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		int _energy_for_vaulthunter;
	public:
		/* canonical form */
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(FragTrap const & object);
		FragTrap &operator=(const FragTrap& rhs);
		~FragTrap();
		/* getters */
		int get_Energy_for_vaulthunter();
		/* setters */
		void set_Energy_for_vaulthunter(int value);
		/* personal-function */
		void vaulthunter_dot_exe(std :: string const & target); //атака случайная (5 способов; -25 поинтов энергии)
};

#endif
