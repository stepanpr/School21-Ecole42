
//
// CPP_Mod04_ex02/emabel/21school
//

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP
# include <iostream>
# include <string>

class ISpaceMarine //класс-интерфейс, поля отсутствуют, все функции виртуальные и определаяются в дочерних классах
{
	public:
		virtual ~ISpaceMarine() {}
		virtual ISpaceMarine* clone() const = 0;
		virtual void battleCry() const = 0;
		virtual void rangedAttack() const = 0;
		virtual void meleeAttack() const = 0;
};

#endif
