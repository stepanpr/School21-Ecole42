
#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <iostream>
# include <string>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:
		RadScorpion(int hp, std::string const & type);
	public:
		/* canonical */
		RadScorpion();
		RadScorpion(RadScorpion const & src);
		RadScorpion &operator= (const RadScorpion& rhs);
		virtual ~RadScorpion();

		/* actions */
		virtual void takeDamage(int damage);
};

#endif
