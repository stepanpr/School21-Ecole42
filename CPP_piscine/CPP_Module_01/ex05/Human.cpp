
#include "Human.hpp"

Human::Human() {}

Human::~Human() {}

//функция, возвращающая поле текущего объекта brain
const Brain& Human::getBrain(void) const
{
	return(this->brain);
}


//функция, возвращающая метод identyfy объекта brain
std::string Human::identify() const
{
	return(this->brain.identify());
}