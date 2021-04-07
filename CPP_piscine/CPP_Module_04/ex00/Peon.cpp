
#include "Peon.hpp"

//==================================CANONIC=FORM===============================

Peon::Peon(std::string name) :  Victim(name), _name(name)  	//при создании экземпляра объекта, 
{															//присваиваем получнное значение name полю _name, 
	std::cout << "   👨‍ Zog zog." << std::endl;					//а также передаем name в конструкор с параметрами класса Victim
}

Peon::Peon(Peon const & src) : Victim(src)
{
	std::cout << "   👨‍ Zog zog." << std::endl;
}

Peon &Peon::operator=(const Peon& rhs)
{
	Victim::operator=(rhs);
	this->_name = rhs.getName();
	return (*this);
}

Peon::~Peon()
{
	std::cout << "   👨 Bleuark..." << std::endl;
}

//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<<(std::ostream &out, Peon &tmp)
{
	std::cout << tmp.sayHello();
	return out;
}

//====================================GETTERS===================================

std::string Peon::getName() const { return this->_name; }

//====================================ACTIONS===================================

std::string Peon::sayHello() const
{
	return " 👨‍💬 I am " + this->getName() + " and I like otters!\n";
}

void Peon::getPolymorphed() const
{
	std::cout << " ✨🐴 " << this->getName() <<" has been turned into a pink pony!" << std::endl;
}
