
//
// CPP_Mod02_ex00/emabel/21school
//

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed 								//канонический класс
{
	public:
		Fixed(void);
		~Fixed(void);

		Fixed(const Fixed &src);            //конструктор копирования (принимаем объект по ссылке)
		Fixed &operator=(const Fixed &rhs);	//оператор присваивания

		int getRawBits (void) const;		//возвращает необработанный значение фиксированной точки
		void setRawBits (int const raw);	//это устанавливает необработанные значение фиксированной точки.
	private:
		int _numFix;						//значение с фиксированной точкой
		int static const _numOfBits = 8;    //количества дробных битов

};

#endif



//http://www.cplusplus.com/articles/y8hv0pDG/
//https://ravesli.com/urok-33-tip-dannyh-s-plavayushhej-tochkoj-floating-point/#toc-0
//https://www.youtube.com/watch?v=3x9nd6Tm7Pc //конструктор копирования
//https://www.youtube.com/watch?v=nMM98LVJn-U //оператор присваивания