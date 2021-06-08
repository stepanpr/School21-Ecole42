
//
// ft_containers/emabel/21school
//

#ifndef STACK_HPP
# define STACK_HPP
# include <iostream>
# include <string>
# include "vector.hpp"

/* stack - контейнер-адаптер элементы которого работают по принципу (LIFO: last in, first out; последним пришел, первым ушел) 
 т.е. элементы добавляются в конец контейнера и удаляются оттуда же (из конца контейнера). */

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		protected:
			Container	_container;

		public:
		/*---------------------------------MEMBER-TYPES----------------------------------*/

			typedef T			value_type;
			typedef size_t		size_type;
			typedef Container	container_type;

    	/*-----------------------------------CONSTRUCTOR--------------------------------*/

			explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) {};

    	/*--------------------------------MEMBER-FUNCTIONS------------------------------*/

			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			void pop();

		/*--------------------------NON-MEMBER FUNCTION OVERLOADS-----------------------*/

			template <class A, class B>
			friend bool operator== (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);
			template <class A, class B>
			friend bool operator!= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);
			template <class A, class B>
			friend bool operator<  (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);
			template <class A, class B>
			friend bool operator<= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);
			template <class A, class B>
			friend bool operator>  (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);
			template <class A, class B>
			friend bool operator>= (const ft::stack<A, B>& lhs, const ft::stack<A, B>& rhs);

	};





	/*================================================================================*/
	/*----------------------------------MEMBER-FUNCTIONS------------------------------*/
	/*================================================================================*/

	template <class T, class Container>
	bool stack<T, Container>::empty() const { return _container.empty(); }

	template <class T, class Container>
	typename stack<T, Container>::size_type stack<T, Container>::size() const { return _container.size(); }

	template <class T, class Container>
	typename stack<T, Container>::value_type& stack<T, Container>::top() { return _container.back(); }

	template <class T, class Container>
	const typename stack<T, Container>::value_type& stack<T, Container>::top() const { return _container.back(); }

	template <class T, class Container>
	void stack<T, Container>::push (const value_type& val) {_container.push_back(val); }

	//в отличие от queue, удаляем последний записанный элемент
	template <class T, class Container>
	void stack<T, Container>::pop() {_container.pop_back(); }





	/*================================================================================*/
	/*---------------------------NON-MEMBER FUNCTION OVERLOADS------------------------*/
	/*================================================================================*/


	template <class T, class Container>
	bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return	(lhs._container == rhs._container); }

	template <class T, class Container>
	bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return	(lhs._container != rhs._container); }

	template <class T, class Container>
	bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return	(lhs._container <  rhs._container); }

	template <class T, class Container>
	bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return	(lhs._container <= rhs._container); }

	template <class T, class Container>
	bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return	(lhs._container >  rhs._container); }

	template <class T, class Container>
	bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return	(lhs._container >= rhs._container); }


};



#endif /* *********************************************************** STACK_H */



// https://www.bestprog.net/ru/2019/09/18/c-the-concept-of-stack-operations-on-the-stack-an-example-implementation-of-the-stack-as-a-dynamic-array-ru/