
//
// ft_containers/emabel/21school
//

#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>
# include <string>

/* List (список) — это двусвязный список, каждый элемент которого содержит 2 указателя: один указывает на следующий 
элемент списка, а другой — на предыдущий элемент списка. List предоставляет доступ только к началу и к концу списка. 
Для поиска значений нужно перебирать список. Преимуществом двусвязного списка является то, что добавление элементов 
происходит очень быстро (без копирования всех элеменов как в массиве) */

namespace ft
{
	template <typename T>
	struct Node
	{
		Node<T>	*_prev;
		Node<T>	*_next;
		T		_element;
		Node(Node<T> *prev, Node<T> *next, const T &value) : _prev(prev), _next(next), _element(value){}

	};

	template <typename T, class Alloc = std::allocator<T> >
	class list
	{
		

		private:
			Alloc		_allocator;
			Node<T>		*_list;
			size_t		_size;


		public:
			/*--------------------------------MEMBER-TYPES--------------------------------*/

			typedef T           value_type;			//тип который пришел
			typedef Alloc		allocator_type;
			typedef T&          reference;			//ссылка на тип
			typedef const T&    const_reference;
			typedef T*          pointer;			//указатель на тип
			typedef const T*    const_pointer;
			typedef size_t      size_type;


    		/*---------------------------------ITERATORS----------------------------------*/

			class iterator
			{
				public:
				iterator():_ptr(NULL){};
				iterator(Node<T> *ptr) { _ptr = ptr;};
				bool operator==(const iterator &other) const { return _ptr == other._ptr; }
				bool operator!=(const iterator &other) const { return _ptr != other._ptr; }
				iterator &operator++() { _ptr=_ptr->_next; return *this; }
				iterator &operator--() { _ptr=_ptr->_prev; return *this; }
				iterator operator++(int) { iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it; }
				iterator operator--(int) { iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it; }		
				T	&operator*(){ return _ptr->_element; }
				Node<T> * getPtr() const{ return _ptr; }
				private:
					Node<T>	*_ptr;
			};

			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL) {}
				reverse_iterator(const reverse_iterator &src){ _ptr = src._ptr; }
				reverse_iterator(Node<T> *ptr){ _ptr = ptr;}
				bool operator==(const reverse_iterator &other) const { return _ptr == other._ptr; }
				bool operator!=(const reverse_iterator &other) const { return _ptr != other._ptr; }
				reverse_iterator &operator++() { _ptr=_ptr->_prev; return *this; }
				reverse_iterator &operator--() { _ptr=_ptr->_next; return *this; }
				reverse_iterator operator++(int) { reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it; }
				reverse_iterator operator--(int) { reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it; }
				T	&operator*() { return _ptr->_element; }
				Node<T> * getPtr() const { return _ptr; }
				private:
					Node<T>	*_ptr;
			};

			class const_reverse_iterator
			{
				public:
				const_reverse_iterator():_ptr(NULL){};
				const_reverse_iterator(const const_reverse_iterator &src) {_ptr = src._ptr;}
				const_reverse_iterator(Node<T> *ptr){_ptr = ptr;};
				bool operator==(const const_reverse_iterator &other) const { return _ptr == other._ptr; }
				bool operator!=(const const_reverse_iterator &other) const { return _ptr != other._ptr; }
				const_reverse_iterator &operator++() {_ptr=_ptr->_prev; return *this; }
				const_reverse_iterator &operator--() {_ptr=_ptr->_next; return *this; }
				const_reverse_iterator operator++(int) { const_reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it; }
				const_reverse_iterator operator--(int) { const_reverse_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it; }
				T	&operator*() const { return _ptr->_element; }
				Node<T> * getPtr() const { return _ptr; };
				private:
					Node<T>	*_ptr;
			};

			class const_iterator
			{
				public:
				const_iterator():_ptr(NULL) {}
				const_iterator(const const_iterator & src) { _ptr = src._ptr; }
				const_iterator(Node<T> *ptr) {_ptr = ptr;};
				bool operator==(const const_iterator &other) const {return _ptr == other._ptr; }
				bool operator!=(const const_iterator &other) const {return _ptr != other._ptr; }
				const_iterator &operator++() { _ptr=_ptr->_next; return *this; }
				const_iterator &operator--() { _ptr=_ptr->_prev; return *this; }
				const_iterator operator++(int) { const_iterator it(this->_ptr); this->_ptr = this->_ptr->_next; return it; }
				const_iterator operator--(int) { const_iterator it(this->_ptr); this->_ptr = this->_ptr->_prev; return it; }			
				T	&operator*() const { return _ptr->_element; }
				Node<T> * getPtr() const { return _ptr; }
				private:
					Node<T>	*_ptr;
			};

			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;


    		/*-----------------------------------CONSTRUCTORS--------------------------------*/

			explicit list (const allocator_type& alloc = allocator_type()); //default constructor(1)
			explicit list (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()); //fill constructor(2)
			list (iterator first, iterator last, const allocator_type& alloc = allocator_type()); //range constructor(3)
			list (const list& x); //copy constructor(4)
			list& operator= (const list& x); //assignation operator
			~list(); //Destructor

			/*------------------------------------CAPACITY-----------------------------------*/

			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			/*----------------------------------ELEMENT-ACCESS-------------------------------*/

			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			/*------------------------------------MODIFIERS----------------------------------*/

			void assign (iterator first, iterator last); //assign: range (1)	
			void assign (size_type n, const value_type& val); //assign: fill (2)
			void	push_front(const T& val);
			void	pop_front();
			void	push_back(const T& val);
			void	pop_back();
			iterator insert (iterator position, const value_type& val); //insert: single element (1)
    		void insert (iterator position, size_type n, const value_type& val); //insert: fill (2)
    		void insert (iterator position, iterator first, iterator last); //insert: range (3)
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap(list &x);
			void resize (size_type n, value_type val = value_type());
			void clear();

			/*------------------------------------OPERATIONS--------------------------------*/

			void splice (iterator position, list& x); //splice: entire list (1)	
			void splice (iterator position, list& x, iterator i); //splice: single element (2)
			void splice (iterator position, list& x, iterator first, iterator last); //splice: element range (3)
			void remove (const value_type& val);
			template <class Predicate>
			void remove_if (Predicate pred);
			void unique(); //unique (1)
			template <class BinaryPredicate> //unique (2)
  			void unique (BinaryPredicate binary_pred);
			void merge (list& x); //merge (1)
			template <class Compare> //merge (2)
			void merge (list& x, Compare comp);
			void sort(); //sort (1)
			template <class Compare> //sort (2)
			void sort (Compare comp);
			void reverse();


	}; /*************************************************************END: class list **********/







	/*================================================================================*/
	/*------------------------------------ITERATORS-----------------------------------*/
	/*================================================================================*/


	template <class T, class Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::begin(){return iterator(_list->_next);}

	template <class T, class Allocator>
	typename list<T, Allocator>::const_iterator list<T, Allocator>::begin() const{return const_iterator(_list->_next);}

	template <class T, class Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::end(){return iterator(_list);}

	template <class T, class Allocator>
	typename list<T, Allocator>::const_iterator list<T, Allocator>::end() const{return const_iterator(_list);}

	template <class T, class Allocator>
	typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rbegin(){return reverse_iterator(_list->_prev);}

	template <class T, class Allocator>
	typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rbegin() const{return const_reverse_iterator(_list->_prev);}

	template <class T, class Allocator>
	typename list<T, Allocator>::reverse_iterator list<T, Allocator>::rend(){return reverse_iterator(_list);};

	template <class T, class Allocator>
	typename list<T, Allocator>::const_reverse_iterator list<T, Allocator>::rend() const{return const_reverse_iterator(_list);}




	/*================================================================================*/
    /*------------------------------------CONSTRUCTORS--------------------------------*/
	/*================================================================================*/



	//default constructor(1)
	//Конструктор по умолчанию. Создает пустой контейнер.
	template <class T, class Allocator>
	list<T, Allocator>::list (const allocator_type& alloc)
		: _allocator(alloc), _size(0)
	{
		_list = new Node<T>(NULL, NULL, value_type());
		_list->_next = _list;
		_list->_prev = _list;

	};

	//fill constructor(2)
	//Создает контейнер из n элементов. Каждый элемент является копией val .
	template <class T, class Allocator>
	list<T, Allocator>::list (size_type n, const value_type& val, const allocator_type& alloc)
		: _allocator(alloc), _size(0)
	{
		_list = new Node<T>(NULL, NULL, value_type());
		_list->_next = _list;
		_list->_prev = _list;
		for (size_type i = 0; i < n; i++)
			push_front(val);
	};

	//range constructor(3)
	//Создает контейнер с содержимым диапазона [first, last)
	template <class T, class Allocator>
	list<T, Allocator>::list(iterator first, iterator last, const allocator_type& alloc) : _allocator(alloc), _size(0)
	{
		_list = new Node<T>(NULL, NULL, value_type());
		_list->_next = _list;
		_list->_prev = _list;
		while (first != last)
		{
			push_back(*first);
			first++;
		}
	};

	//copy constructor(4)
	//создает контейнер с копией элементов x
	template <class T, class Allocator>
	list<T, Allocator>::list(const list& x) : _allocator(x._allocator), _size(0)
	{
		_list = new Node<T>(NULL, NULL, value_type());
		_list->_next = _list;
		_list->_prev = _list;
		*this = x;
	};

	//assignation operator
	//Назначает новое содержимое контейнеру
	template <class T, class Allocator>
	list<T, Allocator>& list<T, Allocator>::operator= (const list& x)
	{
		clear();
		Node<T> *tocopy = x._list->_next;
		while (tocopy != x._list)
		{
			push_back(tocopy->_element);
			tocopy = tocopy->_next;
		}
		return *this;
	};

	//Destructor
	template <class T, class Allocator>
	list<T, Allocator>::~list() { delete _list; };





	/*================================================================================*/
	/*------------------------------------CAPACITY------------------------------------*/
	/*================================================================================*/





	//проверяет, пустой ли контейнер
	template <class T, class Allocator>
	bool list<T, Allocator>::empty() const { return !_size; };

	//возвращает количество элементов
	template <class T, class Allocator>
	typename list<T, Allocator>::size_type list<T, Allocator>::size() const { return _size; };

	//Возвращает максимальное количество элементов
	template <class T, class Allocator>
	typename list<T, Allocator>::size_type list<T, Allocator>::max_size() const { return static_cast<size_type>(-1/sizeof(Node<T>)); };




	/*================================================================================*/
	/*----------------------------------ELEMENT-ACCESS--------------------------------*/
	/*================================================================================*/




	//возвращает ссылку на первый элемент в контейнере
	template <class T, class Allocator>
	typename list<T, Allocator>::reference list<T, Allocator>::front() { return (*begin()); };

	//возвращает константную ссылку на первый элемент в контейнере
	template <class T, class Allocator>
	typename list<T, Allocator>::const_reference list<T, Allocator>::front() const { return (*begin()); };

	//возвращает ссылку на последний элемент в контейнере
	template <class T, class Allocator>
	typename list<T, Allocator>::reference list<T, Allocator>::back() { return _list->_prev->_element; };

	//возвращает константную ссылку на последний элемент в контейнере
	template <class T, class Allocator>
	typename list<T, Allocator>::const_reference list<T, Allocator>::back() const { return _list->_prev->_element; };




	/*================================================================================*/
	/*------------------------------------MODIFIERS-----------------------------------*/
	/*================================================================================*/




	//assign: range (1)	
	//заполняет значениями диапазона
	template <class T, class Allocator>
	void list<T, Allocator>::assign (iterator first, iterator last)
	{
		clear();
		while (first != last)
		{
			push_back(*first);
			first++;
		}
	}

	//assign: fill (2)
	//новое содержимое - это n элементов, каждый из которых инициализирован копией val 
	template <class T, class Allocator>
	void list<T, Allocator>::assign (size_type n, const value_type& val)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	//вставляет элементы в начало списка
	template <class T, class Allocator>
	void	list<T, Allocator>::push_front(const T& val) { insert(begin(), val); }

	//удаляет первый элемент
	template <class T, class Allocator>
	void	list<T, Allocator>::pop_front() { erase(begin()); }

	//добавляет элемент в конец
	template <class T, class Allocator>
	void	list<T, Allocator>::push_back(const T& val) { insert(end(), val); }

	//удаляет последний элемент
	template <class T, class Allocator>
	void	list<T, Allocator>::pop_back() { erase(--end()); }

	//insert: single element (1)
	//Вставляет value перед элементом, на который указывает position
	template <class T, class Allocator>	
	typename list<T, Allocator>::iterator list<T, Allocator>::insert (iterator position, const value_type& val)
	{
		Node<T> *newNode = new Node<T>(position.getPtr()->_prev, position.getPtr(), val);
		position.getPtr()->_prev->_next = newNode;
		position.getPtr()->_prev = newNode;
		// newNode->_next->_prev = newNode;
		// newNode->_prev->_next = newNode;
		_size++;
		return iterator(--position);
	}

	//insert: fill (2)
	//Вставляет n копий value перед элементом, на который указывает position
	template <class T, class Allocator>
	void list<T, Allocator>::insert (iterator position, size_type n, const value_type& val)
	{
		for (size_type i = 0; i<n; i++) 
			insert(position, val);
	}

	//insert: range (3)
	//Вставляет элементы из диапазона [first, last) перед элементом, на который указывает position
	template <class T, class Allocator>
	void list<T, Allocator>::insert (iterator position, iterator first, iterator last)
	{
		while (first != last)
		{
			insert(position, *first);
			first++;
		}
	}

	//удаляет элемент в позиции position
	template <class T, class Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::erase (iterator position)
	{
		position.getPtr()->_next->_prev = position.getPtr()->_prev;
		position.getPtr()->_prev->_next = position.getPtr()->_next;
		iterator ret;
		ret = iterator(position.getPtr()->_next);
		delete position.getPtr();
		_size--;
		return ret;
	}

	//удаляет элементы в диапазоне [first; last)
	template <class T, class Allocator>
	typename list<T, Allocator>::iterator list<T, Allocator>::erase (iterator first, iterator last)
	{
		iterator it = first;
		while (it != last)
			it = erase(it);//returns iterator after the one erased
		return last;
	}


	// template<typename T>
	template <class T, class Allocator>
	void list<T, Allocator>::swap(list &x)
	{
		list<T> tmp;

		tmp = *this;
		*this = x;
		x = tmp;
	}

	//изменяет размер контейнера, чтобы он содержал n элементов;
	//если n меньше текущего размера контейнера, содержимое сокращается до первых n элементов, удаляя все остальные 
	template <class T, class Allocator>
	void list<T, Allocator>::resize (size_type n, value_type val) //= value_type()
	{
		while (n > _size)
			push_back(val);
		while (n < _size)
			pop_back();
	};

	//удаляетвсе элементы из контейнера
	template <class T, class Allocator>
	void list<T, Allocator>::clear() { resize(0); }






	/*================================================================================*/
	/*-------------------------------------OPERATIONS---------------------------------*/
	/*================================================================================*/




	//splice: entire list (1)
	//переносит элементы контейнера x на позицию position
	template <class T, class Allocator>
	void list<T, Allocator>::splice (iterator position, list& x)
	{
		while(x._size)
			splice(position, x, x.begin());
	}



	//splice: single element (2)
	//переносим один элемент i списка x на позицию position
	template <class T, class Allocator>
	void list<T, Allocator>::splice (iterator position, list& x, iterator i)
	{
		i.getPtr()->_prev->_next = i.getPtr()->_next;
		i.getPtr()->_next->_prev = i.getPtr()->_prev;
		x._size--;
		position.getPtr()->_prev->_next = i.getPtr();
		i.getPtr()->_prev = position.getPtr()->_prev;
		position.getPtr()->_prev = i.getPtr();
		i.getPtr()->_next = position.getPtr();
		_size++;
	}

	//splice: element range (3)
	//переносим диапазон с first по last списка x на позицию position
	template <class T, class Allocator>
	void list<T, Allocator>::splice (iterator position, list& x, iterator first, iterator last)
	{
		while (first != last)
		{
			iterator next = first.getPtr()->_next;
			splice(position, x, first);
			first = next;
		}
	}

	//удаляет все элементы val
	template <class T, class Allocator>
	void list<T, Allocator>::remove (const value_type& val)
	{
		iterator it = begin();
		while (it != end())
		{
			iterator next = iterator(it.getPtr()->_next);
			if (*it == val)
				erase(it);
			it = next;
		}
	}

	//удаляет все элементы если Predicate == true
	template <class T, class Allocator>
	template <class Predicate>
	void list<T, Allocator>::remove_if (Predicate pred)
	{
		iterator it = begin();
		iterator next;
		while(it != end())
		{
			next = it.getPtr()->_next;
			if (pred(*it))
				erase(it);
			it = next;
		}
	}

	//unique (1)
	//удаляет все элементы, кроме первого из каждой последующей группы одинаковых элементов в контейнере
	template <class T, class Allocator>
	void list<T, Allocator>::unique()
	{
		iterator it = _list->_next->_next;
		iterator prev = begin();
		iterator next;
		while (it != end())
		{
			next = iterator (it.getPtr()->_next);
			if (*prev == *it)
				erase(it);
			else
				prev = it;
			it = next;
		}
	}

	//unique (2)
	//удаляет все элементы, кроме первого из каждой последующей группы одинаковых элементов в контейнере, если функция сравнения возвращает true
	template <class T, class Allocator>
	template <class BinaryPredicate>//bool function with two args
	void list<T, Allocator>::unique (BinaryPredicate binary_pred)
	{
		iterator it = ++begin();
		iterator prev;
		iterator next;
		while (it != end())
		{
			next = iterator (it.getPtr()->_next);
			prev = iterator (it.getPtr()->_prev);
			if (binary_pred(*prev, *it))
				erase(it);
			else
				prev = it;
			it = next;
		}
	}

	//merge (1)
	//слияние двух списков, значения передаваемого списка ставятся в начало
	template <class T, class Allocator>
	void list<T, Allocator>::merge (list& x) 
	{ 
		splice(end(), x); 
	}

	//merge (2)
	//слияние двух списков, принимает сравнивающую функцию
	template <class T, class Allocator>
	template <class Compare>
	
	void list<T, Allocator>::merge (list& x, Compare comp)
	{
		Node<T> *tmp = this->_list->_next;
        Node<T> *x_tmp = x._list->_next;
        size_t n = this->size();
        size_t m = x.size();
        while (n > 0 && m > 0)
        {
            if (comp(tmp->_element, x_tmp->_element))
            {		//если true, то передвигаемся на next и укорачиваем длину
                tmp = tmp->_next;
                n--;
            }
            else
            {		//усли false, то вставляем элемент, передвигаемся на next и укорачиваем x
                this->insert(tmp, x_tmp->_element);
                x_tmp = x_tmp->_next;
                x.pop_front();
                m--;
            }
        }
	}

	// sort (1)
	//сортировка
	template <class T, class Allocator>
	void list<T, Allocator>::sort() {
		Node<T> *a = _list->_next;
		Node<T> *b = a->_next;
		Node<T> *bef;
		Node<T> *aft;
		while (b != _list)
		{
			if (b->_element < a->_element) 
			{
				bef = a->_prev;
				aft = b->_next;
				bef->_next = b;
				b->_prev = bef;
				b->_next = a;
				a->_prev = b;
				a->_next = aft;
				aft->_prev = a;
				a = _list->_next;
				b = a->_next;
			} 
			else 
			{
				a = a->_next;
				b = b->_next;
			}
		}
	}

	//sort (2)
	//сортировка с Компаратором возвращающим bool
	template <class T, class Allocator>
	template <class Compare>
	void list<T, Allocator>::sort (Compare comp){
		Node<T> *a = _list->_next;
		Node<T> *b = a->_next;
		Node<T> *bef;
		Node<T> *aft;
		while (b != _list)
		{
			if (comp(b->_element, a->_element)) 
			{
				bef = a->_prev;
				aft = b->_next;
				bef->_next = b;
				b->_prev = bef;
				b->_next = a;
				a->_prev = b;
				a->_next = aft;
				aft->_prev = a;
				a = _list->_next;
				b = a->_next;
			} 
			else 
			{
				a = a->_next;
				b = b->_next;
			}
		}				
	}


	//реверс элементов
	template <class T, class Allocator>
	void list<T, Allocator>::reverse() 
	{
		Node<T> *cur = _list->_next;
		Node<T> *next;
		Node<T> *tmp;

		while (cur != _list)
		{
			next = cur->_next;
			tmp = cur->_next;
			cur->_next = cur->_prev;
			cur->_prev = tmp;
			cur = next;
		}
		tmp = cur->_next;
		cur->_next = cur->_prev;
		cur->_prev = tmp;
	}




	/*================================================================================*/
	/*--------------------------------RELATIONAL-OPERATORS----------------------------*/
	/*================================================================================*/

	
	//==(1)	
	template <class T, class Alloc>
	bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::list<T,Alloc>::const_iterator itlhs = lhs.begin();
		typename ft::list<T,Alloc>::const_iterator itrhs = rhs.begin();
		while (itlhs != lhs.end() && itrhs != rhs.end())
		{
			if (*itrhs != *itlhs)
				return false;
			itrhs++;
			itlhs++;
		}
		if (itlhs == lhs.end() && itrhs == rhs.end())
			return true;
		else
			return false;
	}

	//!=(2)	
	template <class T, class Alloc>
	bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return false;
		else
			return true;
	}

	//<(3)	
	template <class T, class Alloc>
	bool operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		typename ft::list<T,Alloc>::const_iterator itlhs = lhs.begin();
		typename ft::list<T,Alloc>::const_iterator itrhs = rhs.begin();
		while (itlhs != lhs.end() && itrhs != rhs.end())
		{
			if (*itlhs < *itrhs)
				return true;
			if (*itlhs > *itrhs)
				return false;
			itrhs++;
			itlhs++;
		}
		if (itlhs == lhs.end() && itrhs != rhs.end())
			return true;
		else
			return false;
	}

	//<=(4)	
	template <class T, class Alloc>
	bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return true;
		else
			return false; 
	}

	//>(5)	
	template <class T, class Alloc>
	bool operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (!(lhs == rhs) && !(lhs < rhs))
			return true;
		else
			return false;
	}

	//>=(6)	
	template <class T, class Alloc>
	bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (!(lhs < rhs))
			return true;
		else
			return false;
	}

	template <class T, class Alloc>
	void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) { x.swap(y); };


};	/***************************************************END: namespace ft **********/


#endif 
