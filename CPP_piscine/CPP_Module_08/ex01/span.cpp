#include "span.hpp"

//==================================CANONIC=FORM===============================

Span::Span(unsigned int N): _N(N)
{
	_v.reserve(N);
}

Span::Span(const Span &copy): _N(copy._N), _v(copy._v) 
{

}

Span &Span::operator=(const Span &op)
{
	if (this != &op)
	{
		_v.clear();
		this->_N = op._N;
		this->_v = op._v;
	}
	return *this;
}

Span::~Span()
{
	_v.clear();
}


//====================================ACTIONS===================================

void Span::addNumber(unsigned int number)						//записываем число
{
    if (_v.size() >= this->_N)
        throw Span::isFull();
    _v.push_back(number);
}

void Span::addNumber(int begin, int end)						//записываем диапазон
{
	if (begin > end)
		throw Span::errorValue();
	if ((this->_v.size() +(end - begin)) > this-> _N )
		throw Span::isFull();
	for (int i = begin; i <= end; i++)
		this->_v.push_back(i);
	
}

void Span::addNumber(std::vector<int> const &vector)			//записываем вектор
{
	if (vector.empty())
		return;
	if ((this->_v.size() + vector.size()) > this->_N )
		throw Span::isFull();
	this->_v.insert(this->_v.end(), vector.begin(), vector.end());
}


//-----------------------------------------------------------------------------


int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw Span::tooSmall();
    int shortestSpan = 2147483647;
    std::vector<int> cp_v(_v);
	//сортируем вектор (числа по возрастанию)
    std::sort(cp_v.begin(), cp_v.end());
    std::vector<int>::iterator prev = cp_v.begin();
    for (std::vector<int>::iterator next = cp_v.begin() + 1; next != cp_v.end(); next++)
    {
        if (*next - *prev < shortestSpan)	//если разница между следующим и предыдушим значением меньше чем shortestSpan из предыдущей итерации,
            shortestSpan = *next - *prev;	//то записываем разницу в shortestSpan и так до тех пор, пока не пройдем по всему вектору;
        prev = next;						//записываем в prev текущее значение next (prev++), а next в свою очередь инкрементируем в конце итерации
    }
    return shortestSpan;
}

int Span::longestSpan() 
{
	if (this->_v.size() < 2)
		throw Span::tooSmall();
	int longestSpan = *std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end());
	return longestSpan;
}


//-----------------------------------------------------------------------------


void Span::showValues()
{
	std::cout << " values in container: ";
	for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}


//-----------------------------------------------------------------------------


const char *Span::isFull::what() const throw()
{
	return ("!imposible: is full");
}

const char *Span::tooSmall::what() const throw()
{
	return ("!imposible: not enough values");
}

const char *Span::errorValue::what() const throw()
{
	return ("!imposible: invalid values");
}
