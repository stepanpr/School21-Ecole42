
#include "AssaultTerminator.hpp"

//==================================CANONIC=FORM===============================

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator& assaultTerminator)
{
	std::cout << "* teleports from space *" << std::endl;
	operator=(assaultTerminator);
}

AssaultTerminator&  AssaultTerminator::operator=(const AssaultTerminator& assaultTerminator)
{
	if (this != &assaultTerminator)
		return (*this);
	return (*this);
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}

//====================================ACTIONS===================================

ISpaceMarine* AssaultTerminator::clone() const //возвращаем клон текущего объекта
{
	return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
