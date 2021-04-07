
#include "Squad.hpp"

//==================================CANONIC=FORM===============================

Squad::Squad() : _AmountUnits(0), _Units(nullptr) {}

Squad::Squad(const Squad &squad) : _AmountUnits(0), _Units(nullptr)
{
	operator=(squad);	//вызываем опреатор присваивания
}

Squad &Squad::operator=(const Squad &squad)
{
	if (this != &squad && squad.getCount())
	{
		for (int i = 0; i < this->_AmountUnits; ++i) 
		{
			delete this->_Units[i]; //удаляем старых юнитов
		}
		delete this->_Units;
		this->_Units = new ISpaceMarine*[squad._AmountUnits];
		for (int i = 0; i < squad._AmountUnits; ++i)
		{
			this->_Units[i] = squad._Units[i]->clone(); //клонируем новых
		}
		this->_AmountUnits = squad._AmountUnits;
	}
	return *this;
}

Squad::~Squad()
{
	if (this->_AmountUnits)
	{
		for (int i = 0; i < this->_AmountUnits; ++i)
			delete this->_Units[i];	//удаляем юнитов
		delete this->_Units;
	}
}

//====================================GETTERS===================================

int Squad::getCount() const
{
	return this->_AmountUnits;
}

ISpaceMarine *Squad::getUnit(int N) const
{
	if (N < this->_AmountUnits && N > -1)
		return (this->_Units[N]);
	return (nullptr);
}

//====================================ACTIONS===================================

int Squad::push(ISpaceMarine *marine)
{
	if (!marine)
		return this->_AmountUnits;
	for(int i = 0; i < this->_AmountUnits; i++)	//проверяем, если такой юнит уже существует
	{
		if (this->_Units[i] == marine)
			return this->_AmountUnits;
	}
	ISpaceMarine **tmp = new ISpaceMarine*[this->_AmountUnits + 1]; //ыделяем память
	for (int i = 0; i < this->_AmountUnits; ++i)
		tmp[i] = this->_Units[i];					//перезаписываем юнитов 
	tmp[this->_AmountUnits] = marine;				//записываем нового юнита
	if (this->_AmountUnits > 0)						
		delete this->_Units;						//удаляем старый массив
	this->_Units = tmp;								//присваиваем новый
	this->_AmountUnits++;							//инкрементируем количество юнитов
	return (this->_AmountUnits);			
}
