
#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T *arr, int len, void (*func)(T const &))
{
	if (!arr)
		return ;
	for (int i = 0; i < len; i++)
		(*func)(arr[i]);
}

template<typename T>
void showValue(T const &value)
{
	std::cout << value;
}

template<typename T>
void showValueWithSpace(T const &value)
{
	std::cout << value << " ";
}

//CLASS AWESOME (from check list)
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

















#endif




