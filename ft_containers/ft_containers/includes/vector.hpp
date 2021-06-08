
//
// ft_containers/emabel/21school
//

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <string>


/* vector — это динамический массив, способный увеличиваться по мере необходимости. 
Обеспечивает произвольный доступ к своим элементам через оператор индексации [] */

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{

		private:
			Alloc		_allocator;
			T			*_vector;	//указатель на начало массива
			size_t		_size;	    //заполненные ячейки
			size_t		_capacity;	//доступные к заполнению ячейки

		public:
			/*---------------------------------MEMBER-TYPES----------------------------------*/

			typedef T           value_type;
			typedef Alloc		allocator_type;
			typedef T&          reference;
			typedef const T&    const_reference;
			typedef T*          pointer;
			typedef const T*    const_pointer;
			typedef size_t      size_type;

			/*---------------------------------ITERATORS----------------------------------*/
			
			class iterator
			{
				public:
				iterator():_ptr(NULL) {}
				iterator(T *ptr) { _ptr = ptr; }
				bool operator==(const iterator &other) const { return _ptr == other._ptr; }
				bool operator!=(const iterator &other) const { return _ptr != other._ptr; }
				iterator &operator++() { _ptr++; return *this; }
				iterator &operator--() { _ptr--; return *this;}
				iterator operator++(int) { iterator it(this->_ptr); this->_ptr++; return it; }
				iterator operator--(int) { iterator it(this->_ptr);this->_ptr--; return it; }			
				T &operator*() { return *_ptr; }
				T *getPtr() const { return _ptr; }
				private:
					T	*_ptr;
			};

			class const_iterator
			{
				public:
				const_iterator():_ptr(NULL) {};
				const_iterator(const const_iterator &src) { _ptr = src._ptr; }
				const_iterator(T *ptr) {_ptr = ptr;}
				bool operator==(const const_iterator &other) const { return _ptr == other._ptr;}
				bool operator!=(const const_iterator &other) const { return _ptr != other._ptr;}
				const_iterator &operator++() { _ptr++; return *this; }
				const_iterator &operator--() { _ptr--; return *this; }
				const_iterator operator++(int) { const_iterator it(this->_ptr); this->_ptr++; return it; }
				const_iterator operator--(int) { const_iterator it(this->_ptr); this->_ptr--; return it; }		
				T &operator*() const { return *_ptr; }
				T *getPtr() const { return _ptr; }
				private:
					T	*_ptr;
			};

			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL) {}
				reverse_iterator(const reverse_iterator &src) { _ptr = src._ptr; }
				reverse_iterator(T *ptr) { _ptr = ptr; }
				bool operator==(const reverse_iterator &other) const { return _ptr == other._ptr;}
				bool operator!=(const reverse_iterator &other) const { return _ptr != other._ptr;}
				reverse_iterator &operator++() { _ptr--; return *this; }
				reverse_iterator &operator--() { _ptr++; return *this; }
				reverse_iterator operator++(int) { reverse_iterator it(this->_ptr); _ptr--; return it; }
				reverse_iterator operator--(int) { reverse_iterator it(this->_ptr); _ptr++; return it; }
				T	&operator*(){ return *_ptr; }
				T * getPtr() const{ return _ptr; }
				private:
					T	*_ptr;
			};

			class const_reverse_iterator
			{
				public:
				const_reverse_iterator():_ptr(NULL) {}
				const_reverse_iterator(const const_reverse_iterator &src) { _ptr = src._ptr; }
				const_reverse_iterator(T *ptr){ _ptr = ptr; }
				bool operator==(const const_reverse_iterator &other) const { return _ptr == other._ptr; }
				bool operator!=(const const_reverse_iterator &other) const { return _ptr != other._ptr; }
				const_reverse_iterator &operator++() { _ptr--; return *this; }
				const_reverse_iterator &operator--() { _ptr++; return *this; }
				const_reverse_iterator operator++(int) { const_reverse_iterator it(this->_ptr); _ptr--; return it; }
				const_reverse_iterator operator--(int) { const_reverse_iterator it(this->_ptr); _ptr++; return it; }
				T	&operator*() const { return *_ptr; }
				T * getPtr() const { return _ptr; }
				private:
					T	*_ptr;
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

			explicit vector (const allocator_type& alloc = allocator_type()); //default constructor(1)
			explicit vector(size_type n, const value_type& val = value_type()); //fill constructor(2)
			template <class InputIterator>										//range constructor(3)
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector(const vector& x); //copy constructor(4)
			vector& operator= (const vector& x); //assignation operator
			~vector(); //Destructor

			/*------------------------------------CAPACITY-----------------------------------*/

			size_type size() const;
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve(size_type n);

			/*----------------------------------ELEMENT-ACCESS-------------------------------*/

		    reference 		operator[](size_type n);
			const_reference operator[](size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference 		front();
			const_reference front() const;
			reference 		back();
			const_reference back() const;

			/*------------------------------------MODIFIERS----------------------------------*/

			void assign (iterator first, iterator last);
			void assign (size_type n, const value_type& val);
			void push_back (const T& val);
			void	pop_back();
			iterator insert (iterator position, const value_type& val);
   			void insert (iterator position, size_type n, const value_type& val);
    		void insert (iterator position, iterator first, iterator last);	
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap(vector& x);
			void clear();


			/*------------------------------PRIVATE-MEMBER-FUNCTIONS--------------------------*/

		private:
			template <class U>
			void swap( U& a, U&b);

	}; /*************************************************************END: class vector ********/







	/*================================================================================*/
	/*------------------------------------ITERATORS-----------------------------------*/
	/*================================================================================*/



	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() { return iterator(_vector); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {return const_iterator(_vector); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::end(){ return iterator(_vector + _size); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const { return const_iterator(_vector+_size); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() { return reverse_iterator(_vector+_size-1); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const { return const_reverse_iterator(_vector+_size-1); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() { return reverse_iterator(_vector-1); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const { return const_reverse_iterator(_vector-1); }



	/*================================================================================*/
    /*------------------------------------CONSTRUCTORS--------------------------------*/
	/*================================================================================*/



	//default constructor(1)
	//Конструктор по умолчанию. Создает пустой контейнер.
	template <class T, class Allocator>
	vector<T, Allocator>::vector (const allocator_type& alloc) 
		: _allocator(alloc), _vector(NULL), _size(0), _capacity(0) {};

	//fill constructor(2)
	//Создает контейнер из n элементов. Каждый элемент является копией val
	template <class T, class Allocator>
	vector<T, Allocator>::vector(size_type n, const value_type& val) : _size(n), _capacity(n)
	{
		_vector = new T[_capacity];
		for (size_type i = 0; i < n; i++){_vector[i] = val;}
	}

	//range constructor(3)
	//Создает контейнер с таким количеством элементов, как диапазон [первый, последний)
	template <class T, class Allocator>
	template<class InputIterator>
	vector<T, Allocator>::vector(InputIterator first, InputIterator last,
			const allocator_type &alloc)
		:  _allocator(alloc), _vector(NULL), _size(0), _capacity(0)
	{
		this->assign(first, last);
	}



	//copy constructor(4)
	//Создает контейнер с копией каждого из элементов в x в том же порядке.
	template <class T, class Allocator>
	vector<T, Allocator>::vector(const vector& x): _size(x.size()), _capacity(x.capacity())
	{
		_vector = new T[x.capacity()];
		for (size_t i = 0; i < x.size(); i++)
			_vector[i] = x._vector[i];
	}

	//assignation operator
	//Копирует все элементы из x в контейнер.
	template <class T, class Allocator>
	vector<T, Allocator>& vector<T, Allocator>::operator= (const vector& x)
	{
		  vector<value_type> tmp(x);
    	swap(tmp);
    	return *this;
	}

	//Destructor
	template <class T, class Allocator>
	vector<T, Allocator>::~vector(){ delete[]_vector; } //~vector(){ delete[]_vector; }



	/*================================================================================*/
	/*------------------------------------CAPACITY------------------------------------*/
	/*================================================================================*/

	//возвращает количество элементов в векторе
	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const{return _size;}

	//возвращает максимальное количество элементов, которое может содержать вектор
	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
	{
		//size_type is always positive so -1 is the max
		return static_cast<size_type>(-1/sizeof(T));
	}

	//изменяет размер контейнера так, чтобы он содержал n элементов
	template <class T, class Allocator>
	void vector<T, Allocator>::resize (size_type n, value_type val)
	{

		if (n < this->_size) 		//если n < size, то урезаем size до n
		{
			size_type i = 0;
			size_type size = this->size();

			while (i + n < size)
			{
				this->pop_back();
				i++;
			}
		}
		else if (n > this->_size) //если n > size, то выделяем память и инициализируем значениями "val" от size до n 
		{
			if (n > this->_capacity)
			{
				if (this->_size * 2 >= n)
					this->reserve(this->_size * 2);
				else
					this->reserve(n);
			}

			while (this->_size < n)
				this->push_back(val);
		}
	
	}

	// возвращает количество элементов, которые могут храниться в выделенной в данный момент памяти
	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const{ return _capacity; }

	//проверяет, пустой ли контейнер
	template <class T, class Allocator>
	bool vector<T, Allocator>::empty() const { return !_size; }

	//резервирует память увелтчивая capacity
	template <class T, class Allocator>
	void vector<T, Allocator>::reserve(size_type n)
	{
		if (n > max_size())
			throw(std::length_error("Out of range"));
		if (n <= _capacity)
			return ;
		if(n > _capacity)
		{
			_capacity = n;
			T *tmp = new T[n];
			for(size_t i = 0; i < _size; i++)
			{
				tmp[i] = _vector[i];
			}
			delete [] _vector;
			_vector = tmp;
		}
		else if (n == 0 && n == _capacity)
			reserve(1);
	}


	/*================================================================================*/
	/*----------------------------------ELEMENT-ACCESS--------------------------------*/
	/*================================================================================*/

	// возвращает ссылку на элемент в позиции n в контейнере вектора. Аналогичная функция-член 
	// vector::at имеет то же поведение, что и эта операторная функция, за исключением того, 
	// что vector :: at проверяется привязкой и сигнализирует, если запрошенная позиция находится 
	// вне диапазона, вызывая исключение out_of_range 
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference 			vector<T, Allocator>::operator[](size_type n)			{ return *(_vector + n); } // _vector[n]

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference 		vector<T, Allocator>::operator[](size_type n) const	{ return *(_vector + n); }

	// возвращает ссылку на элемент в позиции n в векторе, автоматически проверяет, находится ли n в 
	// пределах допустимых элементов в векторе, генерируя исключение out_of_range, если это не так
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference 			vector<T, Allocator>::at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		return _vector[n];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference 		vector<T, Allocator>::at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		return _vector[n];
	}

	// возвращает ссылку на первый элемент вектора; в отличие от члена vector::begin, который 
	// возвращает итератор к тому же элементу, эта функция возвращает прямую ссылку
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference			vector<T, Allocator>::front() { return (*begin()); }

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference		vector<T, Allocator>::front() const { return (*begin()); }

	// возвращает ссылку на последний элемент вектора; в отличие от члена vector :: end , который 
	// возвращает итератор сразу после этого элемента, эта функция возвращает прямую ссылку
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference			vector<T, Allocator>::back() { return *(_vector + _size - 1); }; //_vector[size-1]

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference		vector<T, Allocator>::back() const { return *(_vector + _size - 1); };



	/*================================================================================*/
	/*------------------------------------MODIFIERS-----------------------------------*/
	/*================================================================================*/


	//assign: range (1)	
	//заполняет значениями диапазона
	template <class T, class Allocator>
	void vector<T, Allocator>::assign (iterator first, iterator last) //assign: range (1)	
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
	void vector<T, Allocator>::assign (size_type n, const value_type& val) //assign: fill (2)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	//добавляет новый элемент в конец вектора
	template <class T, class Allocator>
	void vector<T, Allocator>::push_back (const T& val) 					
	{
		if(_size == _capacity)
		reserve(_capacity > 0 ? 2 * _capacity : 2);
		_allocator.construct(_vector + _size, val);
		_vector[++_size - 1] = val;
	}

	//удаляет последний элемент в векторе
	template <class T, class Allocator>
	void	vector<T, Allocator>::pop_back() 
	{ 
		erase(--end()); 
	};

	//insert: single element (1)
	//Вставляет value перед элементом, на который указывает position
 	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::insert (vector<T, Allocator>::iterator position, const value_type& val)
	{

		iterator it = begin();
		vector copy(*this);

		size_type i = 0;
		while (it != position)
		{
			i++;
			it++;
		}
		if (_size + 1 > _capacity)
		{
			if (!_capacity)
				_capacity = 1;
			while (_size + 1 > _capacity)
				_capacity *= 2;
			_vector = new T[_capacity];
		}
		size_type j = 0;
		for (; j != i; j++)
			_vector[j] = copy[j];
		_vector[i] = val;
		for (; j != _size; j++)
			_vector[j + 1] = copy[j];	
		_size++;			
		return iterator(&_vector[i]);
	}
	
	//insert: fill (2)
	//Вставляет n копий value перед элементом, на который указывает position
	template <class T, class Allocator>
	void vector<T, Allocator>::insert (vector<T, Allocator>::iterator position, vector<T, Allocator>::size_type n, const vector<T, Allocator>::value_type& val) //insert: fill (2)	
	{
		for (size_type i = 0; i<n; i++) 
			insert(position, val);
	}

	//insert: range (3)
	//Вставляет элементы из диапазона [first, last) перед элементом, на который указывает position
	template <class T, class Allocator>
	void vector<T, Allocator>::insert (iterator position, iterator first, iterator last)  //insert: range (3)	
	{
		while (first != last)
		{
		position = insert(position, *first);
		++position;
		++first;
		}
	}

	//erase: single (1)
	//удаляет из вектора один элемент
	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase (iterator position)						//удаляет элемент
	{
		iterator next;
		while(position != end())
		{
			next = iterator(position.getPtr() + 1);
			*position = *next;
			position = next;
		}
		_size--;
		return position;
	}

	//erase: range (2)
	//удаляет из вектора диапазон элементов
	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase (iterator first, iterator last)			//удаляет элементы
	{
		iterator it = first;
		while (it != last)
			it = erase(it);
		return last;
	}

	//заменяет содержимое контейнера содержимым x, который является другим списком того же типа
	template <class T, class Allocator>
	void vector<T, Allocator>::swap(vector& x)
	{
		swap(_size, x._size);
		swap(_vector, x._vector);
		swap(_allocator, x._allocator);
		swap(_capacity, x._capacity);
	}


	//удаляет все элементы из контейнера
	template <class T, class Allocator>
	void vector<T, Allocator>::clear() 
	{ 
		resize(0);  //erase(begin(), end());
	}



	/*================================================================================*/
	/*------------------------------PRIVATE-MEMBER-FUNCTIONS--------------------------*/
	/*================================================================================*/



	//меняет местами две переменные
	template <class T, class Allocator>
	template <typename U>
	void vector<T, Allocator>::swap(U& a, U&b)
	{
		U tmp = a;
		a = b;
		b = tmp;
	}



	/*================================================================================*/
	/*--------------------------------RELATIONAL-OPERATORS----------------------------*/
	/*================================================================================*/


	//==(1)	
	template <class T>
	bool operator== (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::const_iterator itlhs = lhs.begin();
		typename ft::vector<T>::const_iterator itrhs = rhs.begin();
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
	template <class T>
	bool operator!= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		if (lhs == rhs)
			return false;
		else
			return true;
	}

	//<(3)	
	template <class T>
	bool operator<(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		typename ft::vector<T>::const_iterator itlhs = lhs.begin();
		typename ft::vector<T>::const_iterator itrhs = rhs.begin();
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
	template <class T>
	bool operator<= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return true;
		else
			return false;
	}

	//>(5)	
	template <class T>
	bool operator>(const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		if (!(lhs == rhs) && !(lhs < rhs))
			return true;
		else
			return false;
	}

	//>=(6)	
	template <class T>
	bool operator>= (const ft::vector<T>& lhs, const ft::vector<T>& rhs)
	{
		if (!(lhs < rhs))
			return true;
		else
			return false;
	}

	template <class T>
	void swap (ft::vector<T>& x, ft::vector<T>& y)
	{
		x.swap(y);
	}






};

#endif /***************************************************END: namespace ft **********/






// http://espressocode.top/how-to-implement-our-own-vector-class-in-c/
// https://arduinoplus.ru/wp-content/uploads/2019/10/cpp-lesson-9.pdf

