
//
// CPP_Mod08_ex02/emabel/21school
//

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <iterator>
# include <stack>
# include <string>



template<class T>
class MutantStack : public std::stack<T> 
{
	public:
		MutantStack(): std::stack<T>() {}
		MutantStack(MutantStack<T> const &cp) : std::stack<T>(cp) {}
		MutantStack<T> &operator=(MutantStack<T> const &rhs) { std::stack<T>::operator=(rhs); return (*this); }
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;				//"container_type" содержит тип базового контейнера, 
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;	//и через наследование мы можем использовать тип итератора в пространстве имен

		iterator begin() { return (this->c.begin()); }					//c - это экземпляр базового контейнера, на котором основан стек,
		iterator end() { return (this->c.end()); }						//который содержит интераторы begin() и end()
		const_iterator cbegin() const { return (this->c.cbegin()); }
		const_iterator cend() const { return (this->c.cend()); }
};



#endif




// https://youtu.be/wFTvBHEnp1A
// https://en.cppreference.com/w/cpp/container/stack
// https://it.wikireading.ru/hzdhSaDAnG
// https://docs.microsoft.com/ru-ru/cpp/dotnet/stack-stl-clr?view=msvc-160