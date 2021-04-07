
#include "Doctor.hpp"

//==================================CANONIC=FORM===============================

Doctor::Doctor(std::string name) :  Victim(name), _name(name)  	//при создании экземпляра объекта, 
{																//присваиваем получнное значение name полю _name, 
	std::cout << "   🧔 Whom to treat?" << std::endl;			//а также передаем name в конструкор с параметрами класса Victim
}

Doctor::Doctor(Doctor const & src) : Victim(src)
{
	std::cout << "   🧔 Whom to treat?" << std::endl;
}

Doctor &Doctor::operator=(const Doctor& rhs)
{
	Victim::operator=(rhs);
	this->_name = rhs.getName();
	return (*this);
}

Doctor::~Doctor()
{
	std::cout << "   🧔 Oh nooo" << std::endl;
}

//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<<(std::ostream &out, Doctor &tmp)
{
	std::cout << tmp.sayHello();
	return out;
}

//====================================GETTERS===================================

std::string Doctor::getName() const { return this->_name; }

//====================================ACTIONS===================================

std::string Doctor::sayHello() const
{
	return " 🧔💬 I am " + this->getName() + " and I like camels!\n";
}

void Doctor::getPolymorphed() const
{
	std::cout << " ✨🐫 " << this->getName() <<" has been turned into a camel!" << std::endl;
}
