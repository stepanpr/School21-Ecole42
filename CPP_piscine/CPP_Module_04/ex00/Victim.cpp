
#include "Victim.hpp"

//==================================CANONIC=FORM===============================

Victim::Victim(){}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "   🚶‍ Some random victim called " << name << " just appeared!" << std::endl;
}
Victim::Victim(Victim const & src)
{
	// operator=(src);
	*this = src;
}

Victim &Victim::operator=(const Victim& rhs)
{
	if (this != &rhs)
		this->_name = rhs._name;
	return (*this);
}

Victim::~Victim()
{
	std::cout << "   ⚰️  Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<<(std::ostream &out, Victim &tmp)
{
	std::cout << tmp.sayHello();
	return out;
}

//====================================GETTERS===================================

std::string Victim::getName() const { return this->_name; }


//====================================ACTIONS===================================

std::string Victim::sayHello() const
{
	return " 👤💬 I am " + this->getName() + " and I like otters!\n";
}

void Victim::getPolymorphed() const
{
	std::cout << " ✨🐑 " << this->getName() << " has been turned into a cute little sheep!" << std::endl;

}
