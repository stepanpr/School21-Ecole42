
#include "Fixed.hpp"

Fixed::Fixed(void) : _numFix(0)									//конструктор по-умолчанию
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)												//деструктор
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src)									//конструктор копирования
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_numFix = src.getRawBits();
	*this = src;
	return;
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
  std::cout << "setRawBits member function called" << std::endl;
  this->_numFix = raw;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return this->_numFix;
}
