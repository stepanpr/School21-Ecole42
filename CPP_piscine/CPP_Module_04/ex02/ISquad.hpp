//
// CPP_Mod04_ex02/emabel/21school
//

#ifndef ISQUAD_HPP
#define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad //класс-интерфейс, поля отсутствуют, все функции виртуальные и определаяются в дочерних классах
{ 
public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;				//количество юнитов в отряде
	virtual ISpaceMarine* getUnit(int) const = 0; 	//указатель на юнита по индексу
	virtual int push(ISpaceMarine*) = 0;			//добавляет юнита в конец отряда; возвращает количество юнитов в отряде после операции
};

#endif 
