//
// CPP_Mod04_ex02/emabel/21school
//

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"

class Squad : public ISquad 
{
	public:
		/* canonical */
		Squad();
		Squad(const Squad&);
		Squad& operator=(const Squad&);
		virtual ~Squad();
		/* actions */
		virtual int getCount() const;				//количество юнитов в отряде
		virtual ISpaceMarine *getUnit(int N) const;	//указатель на юнита по индексу
		virtual int push(ISpaceMarine *marine);		//добавляет юнита в конец отряда; возвращает количество юнитов в отряде после операции
	private:
		int _AmountUnits;
		ISpaceMarine **_Units;
};

#endif
