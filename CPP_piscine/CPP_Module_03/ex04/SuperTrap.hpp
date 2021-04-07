

#ifndef	SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"


// в родителях (FragTrap и NinjaTrap) прописываем "virtual", 
// что позвляет при создании внука (SuperTrap), 
// избежать создания лишнего класса деда (ClapTrap)

class SuperTrap : public FragTrap, public NinjaTrap
{

	public:
		/* canonical form */
		SuperTrap();
		SuperTrap(std::string const &Name);
		SuperTrap(SuperTrap const & object);
		SuperTrap &operator=(const SuperTrap& rhs);
		~SuperTrap();
		/* action-functions */
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
};

#endif