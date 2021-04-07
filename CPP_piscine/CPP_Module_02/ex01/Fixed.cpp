
#include "Fixed.hpp"

Fixed::Fixed(void) : _numFix(0)									//конструктор по-умолчанию
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _numFix(num)						//конструктор с параметрами
{
	std::cout << "Int constructor called" << std::endl;
	_numFix = (num << this->_numOfBits);
}

Fixed::Fixed(float const num) : _numFix(num)					//конструктор с параметрами
{
	std::cout << "Float constructor called" << std::endl;
	_numFix = (roundf(num * (1 << this->_numOfBits)));
}

Fixed::Fixed(const Fixed & src)									//конструктор копирования
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)												//деструктор
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &rhs)						//оператор присваивания
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
    	this->_numFix = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(const int raw)
{
  this->_numFix = raw;
}

int Fixed::getRawBits(void) const
{
  return this->_numFix;
}

int Fixed::toInt(void) const
{
	return (this->_numFix >> this->_numOfBits);
}

float Fixed::toFloat(void) const 
{
  return (float(this->_numFix) / float((1 << this->_numOfBits)));
}

std::ostream &operator<<(std::ostream &out, const Fixed &tmp)  		//перегрузочный оператор вывода
{ 
  out << tmp.toFloat();
  return out;
}
