
//
// ft_containers/emabel/21school
//

#ifndef QUEUE_HPP
# define QUEUE_HPP
# include <iostream>
# include <string>
# include "list.hpp"

/* queue - контейнер-адаптер, элементы которого работают по принципу (FIFO - first in, first out; первым пришел, первым ушел) 
т.е. элементы добавляются в конец контейнера, но удаляются из начала контейнера. */

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
		protected:
			Container	_container;

		public:
		/*---------------------------------MEMBER-TYPES----------------------------------*/

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

    	/*-----------------------------------CONSTRUCTOR--------------------------------*/

			explicit queue (const container_type& ctnr = container_type()) : _container(ctnr) {};

    	/*--------------------------------MEMBER-FUNCTIONS------------------------------*/

			bool empty() const;
			size_type size() const;
			value_type& back();
			const value_type& back() const;
			value_type& front();
			const value_type& front() const;
			void push (const value_type& val);
			void pop();

		/*--------------------------NON-MEMBER FUNCTION OVERLOADS-----------------------*/

			template <class A, class B>
			friend bool operator== (const ft::queue<A, B>& lhs, const ft::queue<A, B>& rhs);
			template <class A, class B>
			friend bool operator!= (const ft::queue<A, B>& lhs, const ft::queue<A, B>& rhs);
			template <class A, class B>
			friend bool operator<  (const ft::queue<A, B>& lhs, const ft::queue<A, B>& rhs);
			template <class A, class B>
			friend bool operator<= (const ft::queue<A, B>& lhs, const ft::queue<A, B>& rhs);
			template <class A, class B>
			friend bool operator>  (const ft::queue<A, B>& lhs, const ft::queue<A, B>& rhs);
			template <class A, class B>
			friend bool operator>= (const ft::queue<A, B>& lhs, const ft::queue<A, B>& rhs);

	}; /*************************************************************END: class queue ********/






	/*================================================================================*/
	/*----------------------------------MEMBER-FUNCTIONS------------------------------*/
	/*================================================================================*/


	template <class T, class Container>
	bool queue<T, Container>::empty() const { return _container.empty(); }

	template <class T, class Container>
	typename queue<T, Container>::size_type queue<T, Container>::size() const { return _container.size(); }

	template <class T, class Container>
	typename queue<T, Container>::value_type& queue<T, Container>::back() { return _container.back(); }

	template <class T, class Container>
	const typename queue<T, Container>::value_type& queue<T, Container>::back() const { return _container.back(); }

	template <class T, class Container>
	typename queue<T, Container>::value_type& queue<T, Container>::front() { return _container.front(); }

	template <class T, class Container>
	const typename queue<T, Container>::value_type& queue<T, Container>::front() const { return _container.front(); }

	template <class T, class Container>
	void queue<T, Container>::push (const queue<T, Container>::value_type& val) { _container.push_back(val); }

	template <class T, class Container>
	void queue<T, Container>::pop() { _container.pop_front(); }






	/*================================================================================*/
	/*---------------------------NON-MEMBER FUNCTION OVERLOADS------------------------*/
	/*================================================================================*/


	template <class T, class Container>
	bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return	(lhs._container == rhs._container); }

	template <class T, class Container>
	bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return	(lhs._container != rhs._container); }

	template <class T, class Container>
	bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return	(lhs._container <  rhs._container); }

	template <class T, class Container>
	bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return	(lhs._container <= rhs._container); }

	template <class T, class Container>
	bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return	(lhs._container >  rhs._container); }

	template <class T, class Container>
	bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) { return	(lhs._container >= rhs._container); }


};


#endif /***************************************************END: namespace ft **********/



// https://prog-cpp.ru/data-queue/
// https://bestprogrammer.ru/programmirovanie-i-razrabotka/ochered-queue-v-c-realizatsiya-i-ispolzovanie
// https://www.bestprog.net/ru/2019/09/26/c-queue-general-concepts-ways-to-implement-the-queue-implementing-a-queue-as-a-dynamic-array-ru/
// https://ru.stackoverflow.com/questions/479987/%D0%A7%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%B0%D0%B4%D0%B0%D0%BF%D1%82%D0%B5%D1%80
// http://cppstudio.com/post/5159/
// http://procplusplus.blogspot.com/2011/06/11-c-stl-stack-and-queue.html