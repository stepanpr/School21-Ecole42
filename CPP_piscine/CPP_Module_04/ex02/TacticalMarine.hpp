
//
// CPP_Mod04_ex02/emabel/21school
//

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine 
{
public:
	/* canonical */
	TacticalMarine();
	TacticalMarine(const TacticalMarine&);
	TacticalMarine& operator=(const TacticalMarine&);
	virtual ~TacticalMarine();

	/* actions */
	ISpaceMarine* clone() const; //клон текущего объекта
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
