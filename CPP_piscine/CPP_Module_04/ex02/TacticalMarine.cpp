
#include "TacticalMarine.hpp"

//==================================CANONIC=FORM===============================

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &tacticalMarine)
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
	operator=(tacticalMarine);
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &tacticalMarine)
{
	if (this != &tacticalMarine)
		return (*this);
	return (*this);
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}



//====================================ACTIONS===================================

ISpaceMarine *TacticalMarine::clone() const	//возвращаем клон текущего объекта
{
	return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}