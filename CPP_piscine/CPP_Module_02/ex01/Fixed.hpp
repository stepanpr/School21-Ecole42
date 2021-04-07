
//
// CPP_Mod02_ex00/emabel/21school
//

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed 								//канонический класс
{
	public:
		Fixed(void);						//дефолтный конструктор
		Fixed(int const num);				//конструктор с параметрами
		Fixed(float const num);				//конструктор с параметрами
		Fixed(const Fixed &src);            //конструктор копирования
		~Fixed(void);						//деструктор

		Fixed &operator=(const Fixed &rhs);	//оператор присваивания

		int getRawBits (void) const;		//возвращает значение
		void setRawBits (int const raw);	//устанавливает значение
		float toFloat (void) const;			//преобразует значение с фиксированной запятой в значение с плавающей запятой
		int toInt (void) const;				//преобразует значение с фиксированной точкой в ​​целочисленное значение

	private:
		int _numFix;						//значение с фиксированной точкой
		int static const _numOfBits = 8;    //количество дробных битов

	
};

	std::ostream &operator<<(std::ostream &os, const Fixed &tmp); //перегрузка оператора ввода

#endif


//http://www.cplusplus.com/articles/y8hv0pDG/
//https://ravesli.com/urok-33-tip-dannyh-s-plavayushhej-tochkoj-floating-point/#toc-0
//https://ravesli.com/urok-133-peregruzka-operatorov-vvoda-i-vyvoda/#toc-0
//https://compgraphics.info/2D/fixed.php