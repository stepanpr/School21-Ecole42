#include "Cure.hpp"

//==================================CANONIC=FORM===============================

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure( Cure const & obj )
{
	*this = obj;
}

Cure&	Cure::operator=( Cure const & rhs)
{
	this->setXp(rhs.getXP());
	this->setType(rhs.getType());
	return ( *this );
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

//====================================ACTIONS===================================

void Cure::use(ICharacter& target)
{
	this->setXp(this->getXP() + 10);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
