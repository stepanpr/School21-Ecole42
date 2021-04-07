
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <string>
# include <iostream>
# include <time.h>

template <typename T>
class Array
{
private:
	T               *_arr;
	unsigned int    _len;

public:
	Array() : _arr(nullptr), _len(0) {};						//дефолтный конструктор
	Array(unsigned int n) : _arr(new T[n]), _len(n) {};			//конструктор с параметром - количество элементов массива
	Array(const Array& rhs)	{ *this = rhs; };					//конструктор копирования
	
	Array& operator=(const Array& rhs)							//оператор присваивания				
	{
		if (this == &rhs)
			return *this;
		else
		{
			_len = rhs.size();
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_arr[i] = rhs._arr[i];
		}
		return *this;
	};

	virtual ~Array() { delete []_arr; };						//деструктор
	

	T& operator[](unsigned int i)								//перегрузка оператора индексации
	{
		if (i < 0 || i >= _len)
			throw outOfRange();
		return (_arr[i]);
	};

	const T& operator[](unsigned int i) const 					//перегрузка оператора индексации с const
	{
		if (i < 0 || i >= _len)
			throw outOfRange();
		return (_arr[i]);
	};
	
	class outOfRange : public std::exception					//исклеючение
	{
		public:
		virtual const char* what() const throw()
		{
			return ("Error: out of range");
		};
	};
	
	unsigned int size(void) const									//длина массива
	{
		return(_len);
	};
};

#endif


// https://ravesli.com/urok-151-kontejnernye-klassy/
// https://ravesli.com/urok-175-shablony-klassov/
// https://ravesli.com/urok-179-chastichnaya-spetsializatsiya-shablona/
// https://ravesli.com/urok-138-peregruzka-operatora-indeksatsii/
// https://evileg.com/ru/post/289/