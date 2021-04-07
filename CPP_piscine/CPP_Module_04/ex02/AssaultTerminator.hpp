
//
// CPP_Mod04_ex02/emabel/21school
//

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine 
{
	public:
		/* canonical */
		AssaultTerminator();
		AssaultTerminator(const AssaultTerminator&);
		AssaultTerminator& operator=(const AssaultTerminator&);
		virtual ~AssaultTerminator();
		/* actions */
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif