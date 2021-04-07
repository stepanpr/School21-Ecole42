
#include "Sorcerer.hpp"
#include "Victim.hpp"

//==================================CANONIC=FORM===============================

Sorcerer::Sorcerer(){}

Sorcerer::Sorcerer(std::string const name, std::string const title) : _name(name), _title(title)
{
	std::cout << "   💫 " << this->_name << ", " << title << "is born" << std::endl;
}
Sorcerer::Sorcerer(Sorcerer const & src) : _name(src._name), _title(src._title)
{
	std::cout << this->_name << ", " << _title << "is born" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return (*this);
}

Sorcerer::~Sorcerer()
{
	std::cout << "   ⚰️  " << this->getName() << ", " << this->getTitle() << "is dead. Consequences will never be the same!" << std::endl;
}

//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<<(std::ostream &out, const Sorcerer &tmp)
{
	// std::cout << "I am " << tmp.getName() << ", " << tmp.getTitle() << " and I like ponies!" << std::endl;
	std::cout << tmp.sayHello();
	return out;
}

//====================================GETTERS===================================

std::string Sorcerer::getName() const { return this->_name; }
std::string Sorcerer::getTitle() const { return this->_title; }

//====================================ACTIONS===================================

std::string Sorcerer::sayHello() const //std::string name, std::string title)
{
	return " 🧙‍💬 I am " + this->getName() + ", " + this->getTitle() + " and I like ponies!\n";
}

void Sorcerer::polymorph(Victim const & v) const 
{
	v.getPolymorphed();
}