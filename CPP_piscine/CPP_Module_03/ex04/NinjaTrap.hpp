

#ifndef	NINJA_HPP
# define NINJA_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
	public:
		/* canonical form */
		NinjaTrap();
		NinjaTrap(std::string Name);
		NinjaTrap(NinjaTrap const & object);
		NinjaTrap &operator=(const NinjaTrap& rhs);
		~NinjaTrap();
		/* personal-function */
		void ninjaShoebox(FragTrap &frend);
		void ninjaShoebox(ScavTrap &frend);
		void ninjaShoebox(NinjaTrap &frend);
		void ninjaShoebox(ClapTrap &frend);
};

#endif