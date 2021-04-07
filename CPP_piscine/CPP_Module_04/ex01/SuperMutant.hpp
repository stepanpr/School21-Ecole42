
#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>
# include <string>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:
		SuperMutant(int hp, std::string const & type);
	public:
		/* canonical */
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		SuperMutant &operator= (const SuperMutant& rhs);
		virtual ~SuperMutant();

		/* actions */
		virtual void takeDamage(int damage);
};

#endif
