
//
// ft_containers/emabel/21school
//

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>

/* map - ассоциативный контейнер, в котором каждый элемент является парой «ключ-значение». «Ключ» используется для сортировки и 
индексации данных и должен быть уникальным, а «значение» — это фактические данные. */

namespace ft
{
	template <typename T>
	struct less 
	{ 
		bool operator()(const T &a,const T &b) const { return (a < b); }
	};

	//шаблон, который позволяет хранить два разнородных объекта как единое целое
	template <class Key, class T>
	struct pair
	{
		pair(Key first, T second): first(first), second(second) {};
		pair():first(), second() {};
		const Key	first;
		T			second;
	};

	template <class Key, class T>
	struct mNode
	{
		mNode(pair<Key, T> pair): _pair(pair), _prev(NULL), _next(NULL) {};
		mNode(): _pair(), _prev(NULL), _next(NULL) {};
		pair<Key, T>	_pair;
		mNode<Key, T>	*_prev;
		mNode<Key, T>	*_next;	
	};

	template < class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map
	{

		private:
			mNode<Key, T>	*_map;
			Compare		_keycomp;
			size_t		_size;

		public:

			/*---------------------------------MEMBER-TYPES----------------------------------*/

			typedef Key 									key_type;
			typedef T 										mapped_type;
			typedef ft::pair<key_type, mapped_type> 		value_type;
			typedef ft::less<key_type>						key_compare;
			typedef Alloc 									allocator_type;
			typedef typename allocator_type::reference		reference;
			typedef typename	allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef size_t 									size_type;


    		/*---------------------------------ITERATORS----------------------------------*/

			class iterator
			{
				public:
				iterator():_ptr(NULL){};
				iterator(mNode<Key, T> *ptr) { _ptr = ptr; }
				bool operator==(const iterator &other) const { return _ptr==other._ptr; }
				bool operator!=(const iterator &other) const { return _ptr!=other._ptr; }
				iterator &operator++() {
					_ptr = _ptr->_next;
					return *this; }
				iterator &operator--() {
					_ptr=_ptr->_prev;
					return *this;}
				iterator operator++(int) {
					iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it;};
				iterator operator--(int) {
					iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it;}
				pair<Key, T> operator*() {
					if(_ptr)
						return (_ptr->_pair);
					else
						return (pair<Key, T>());
				};
				pair<Key, T> *operator->() {
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL); }
				mNode<Key, T> *getPtr() const { return _ptr; }
				private:
				mNode<Key, T>	*_ptr;
			};
			class const_iterator
			{
				public:
				const_iterator():_ptr(NULL) {};
				const_iterator(const const_iterator & src){ _ptr = src._ptr; }
				const_iterator(mNode<Key, T> *ptr){ _ptr = ptr; }
				bool operator==(const const_iterator&other)const{ return _ptr==other._ptr; }
				bool operator!=(const const_iterator&other)const{ return _ptr!=other._ptr; }
				const_iterator &operator++() {
					_ptr = _ptr->_next;
					return *this; }
				const_iterator &operator--() {
					_ptr=_ptr->_prev;
					return *this; }
				const_iterator operator++(int) {
					const_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it; }
				const_iterator operator--(int) {
					const_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it; }
				pair<Key, T> *operator->() {
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL); }
				mNode<Key, T> *getPtr() const { return _ptr; }
				private:
				mNode<Key, T>	*_ptr;
			};
			class reverse_iterator
			{
				public:
				reverse_iterator():_ptr(NULL) {}
				reverse_iterator(const reverse_iterator & src){ _ptr = src._ptr; }
				reverse_iterator(mNode<Key, T> *ptr) { _ptr = ptr; }
				bool operator==(const reverse_iterator &other) const { return _ptr==other._ptr; }
				bool operator!=(const reverse_iterator &other) const { return _ptr!=other._ptr; }
				reverse_iterator &operator++() {
					_ptr = _ptr->_prev;
					return *this; }
				reverse_iterator &operator--() {
					_ptr=_ptr->_next;
					return *this; }
				reverse_iterator operator++(int) {
					reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it; }
				reverse_iterator operator--(int) {
					reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it; }
				pair<Key, T> *operator->(){
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL);};
				mNode<Key, T> *getPtr() const { return _ptr; }
				private:
				mNode<Key, T>	*_ptr;
			};
			class const_reverse_iterator
			{
				public:
				const_reverse_iterator():_ptr(NULL) {}
				const_reverse_iterator(const const_reverse_iterator & src) {_ptr = src._ptr;}
				const_reverse_iterator(mNode<Key, T> *ptr){_ptr = ptr;};
				bool operator==(const const_reverse_iterator &other) const { return _ptr==other._ptr; }
				bool operator!=(const const_reverse_iterator &other) const { return _ptr!=other._ptr; }
				const_reverse_iterator &operator++() {
					_ptr = _ptr->_prev;
					return *this; }
				const_reverse_iterator &operator--() {
					_ptr=_ptr->_next;
					return *this; }
				const_reverse_iterator operator++(int) {
					const_reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_prev;
					return it; }
				const_reverse_iterator operator--(int) {
					const_reverse_iterator it(this->_ptr);
					this->_ptr = this->_ptr->_next;
					return it; }
				pair<Key, T> *operator->(){
					if(_ptr)
						return &(_ptr->_pair);
					else
						return (NULL);};
				mNode<Key, T> *getPtr() const{return _ptr;}
				private:
				mNode<Key, T>	*_ptr;
			};

			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
	

    		/*-----------------------------CLASS VALUE_COMPARE------------------------------*/

			class value_compare
			{
				public:
					value_compare(const key_compare& compare) : _comp(compare)
					{}

					bool operator() (const value_type& a, const value_type& b) const
					{
						return _comp(a.first, b.first);
					}
				private:
					key_compare _comp;
			};

    		/*-----------------------------------CONSTRUCTORS--------------------------------*/

			//default constructor(1)
			explicit map (const key_compare& comp = key_compare());
			//range constructor(2)
			map(iterator first, iterator last, const key_compare& comp = key_compare());
			//copy constructor(3)
			map(const map& x);
			map& operator= (const map& x);
			//Destructor
			~map();


			/*------------------------------------CAPACITY-----------------------------------*/

			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			/*----------------------------------ELEMENT-ACCESS-------------------------------*/

			mapped_type& operator[] (const key_type& k);

			/*------------------------------------MODIFIERS----------------------------------*/

			//insert: single element(1)	
			pair<iterator,bool> insert (const value_type& val);
			//insert: with hint(2)	
			iterator insert (iterator position, const value_type& val);
			//insert: range(3)
			void insert (iterator first, iterator last);
			//erase(1)	
		    void erase (iterator position);
			//erase(2)	
			size_type erase (const key_type& k);
			//erase(3)	
			void erase (iterator first, iterator last);
			void swap (map& x);
			void clear();

			/*------------------------------------OBSERVERS----------------------------------*/

			key_compare key_comp() const;
			value_compare value_comp() const;

			/*-----------------------------------OPERATIONS----------------------------------*/

			iterator find (const key_type& k);

			const_iterator find (const key_type& k) const; 
			size_type count (const key_type& k) const;
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);



	};  /*************************************************************END: class map **********/









	/*================================================================================*/
	/*------------------------------------ITERATORS-----------------------------------*/
	/*================================================================================*/

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::begin(){return iterator(_map->_next);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::begin() const {return const_iterator(_map->_next);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::end(){return iterator(_map);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::end() const{return const_iterator(_map);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rbegin(){return reverse_iterator(_map->_prev);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rbegin() const{return const_reverse_iterator(_map->_prev);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rend(){return reverse_iterator(_map);}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rend() const{return const_reverse_iterator(_map);}



    /*================================================================================*/
   	/*------------------------------------CONSTRUCTORS--------------------------------*/
	/*================================================================================*/

	//default constructor(1)
	//Конструктор по умолчанию. Создаёт пустой контейнер
	template <class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::map (const key_compare& comp) : _keycomp(comp), _size(0)
	{
		_map = new mNode<Key, T>();
		_map->_prev = _map;
		_map->_next = _map;
	}

	//range constructor(2)
	//Создаёт контейнер с содержимым из диапазона [first, last).
	template <class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::map(iterator first, iterator last, const key_compare& comp) : _keycomp(comp), _size(0)
	{
		_map = new mNode<Key, T>();
		_map->_prev = _map;
		_map->_next = _map;
		insert(first, last);
	}

	//copy constructor(3)
	//Конструктор копирования. Создает контейнер с копией содержимого other
	template <class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::map(const map& x): _keycomp(x._keycomp), _size(0)
	{
		_map = new mNode<Key, T>();
		_map->_prev = _map;
		_map->_next = _map;
		insert(iterator(x._map->_next), iterator(x._map));
	}

	//Назначает новое содержимое контейнеру
	template <class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>& map<Key, T, Compare, Allocator>::operator= (const map& x)
	{
		clear();
		_keycomp = x._keycomp;
		insert(iterator(x._map->_next), iterator(x._map));
		return *this;
	}

	//Destructor
	template <class Key, class T, class Compare, class Allocator>
	map<Key, T, Compare, Allocator>::~map() { delete _map; }








	/*================================================================================*/
	/*------------------------------------CAPACITY------------------------------------*/
	/*================================================================================*/


	//проверяет пуст ли контейнер
	template <class Key, class T, class Compare, class Allocator>
	bool map<Key, T, Compare, Allocator>::empty() const 
	{ return !_size; }

	//возвращает количество элементов
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size() const 
	{ return _size; }

	//возвращает максимально возможное количество элементов
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size() const
	{
		//size_type is always positive so -1 is the max
		return static_cast<size_type>(-1/sizeof(mNode<Key, T>));
	}







	/*================================================================================*/
	/*----------------------------------ELEMENT-ACCESS--------------------------------*/
	/*================================================================================*/


	//если k соответствует ключу элемента в контейнере, функция возвращает ссылку на его отображенное значение.
	//если k не соответствует ключу какого-либо элемента в контейнере, функция вставляет новый элемент с этим 
	//ключом и возвращает ссылку на его сопоставленное значение.
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::mapped_type& map<Key, T, Compare, Allocator>::operator[] (const key_type& k)
	{
		iterator it = begin();
		while (it != end() && _keycomp(it->first, k))
			it++;
		if (it != end() && it->first == k)	//элемент найден, возвращаем ссылку на значение (second)
			return (it->second);
		else								//элемент не найден
			insert(pair<Key, T>(k, T()));
		return ((*this)[k]);
	}








	/*================================================================================*/
	/*------------------------------------MODIFIERS-----------------------------------*/
	/*================================================================================*/


	
	// Расширяет контейнер, вставляя новые элементы, увеличивая размер контейнера 
	// на количество вставленных элементов. Поскольку ключи элементов на карте уникальны, 
	// операция вставки проверяет, имеет ли каждый вставленный элемент ключ, эквивалентный ключу 
	// элемента, уже находящегося в контейнере, и если да, элемент не вставляется, возвращая 
	// итератор к этому существующему элементу.

	//insert: single element(1)
	// Возвращает пару. Ее член pair::first установлен на итератор, указывающий либо на вновь вставленный элемент, 
	// либо на элемент с эквивалентным ключом на карте. Для элемента pair::second в паре устанавливается значение true, 
	// если был вставлен новый элемент, или false, если эквивалентный ключ уже существовал.
	template <class Key, class T, class Compare, class Allocator>
	typename ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool> 		map<Key, T, Compare, Allocator>::insert (const value_type& val)
	{
		typename map<Key, T, Compare, Allocator>::iterator it = map<Key, T, Compare, Allocator>::begin();
		while (it != map<Key, T, Compare, Allocator>::end() && _keycomp(it->first, val.first))
			it++;
		if (it != map<Key, T, Compare, Allocator>::end() && it->first == val.first) //если элемент с заданным ключом существует
			return (ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool>(it, false));
		else
		{
			_size++;
			mNode<Key, T> *new_mNode = new mNode<Key, T>(val);						//если элемент с заданным ключом отсутствует
			new_mNode->_next = it.getPtr();
			new_mNode->_prev = it.getPtr()->_prev;
			it.getPtr()->_prev->_next = new_mNode;
			it.getPtr()->_prev = new_mNode;
			return (pair<typename map<Key, T, Compare, Allocator>::iterator, bool>(iterator(new_mNode), true));
		}
	}

	//insert: with hint(2)
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator 		map<Key, T, Compare, Allocator>::insert (iterator position, const value_type& val)
	{
		(void)position;
		return insert(val).first;
	}

	//insert: range(3)
	// Вставка элементов из диапазона [first, last)
	template <class Key, class T, class Compare, class Allocator>
	void 		map<Key, T, Compare, Allocator>::insert (iterator first, iterator last)
	{
		for (;first!=last; first++)
			insert(pair<Key, T>(first->first, first->second));
	}

	//erase(1)
	// Удаляет элемент по итератору pos
	template <class Key, class T, class Compare, class Allocator>
	void map<Key, T, Compare, Allocator>::erase (iterator position)
	{
		iterator it = begin();
		while (it != end() && it != position) 	//ищем position
			it++;
		if (it == end())					  	//return если дошли до конца
			return;
		else									//если нашли элемент, то удаляем его
		{
			mNode<Key, T> *prev = it.getPtr()->_prev;
			mNode<Key, T> *next = it.getPtr()->_next;
			prev->_next = next;
			next->_prev = prev;
			delete (it.getPtr());
			_size--;
		}
	}

	//erase(2)
	// Ключ элемента key_type, который нужно удалить
	template <class Key, class T, class Compare, class Allocator>	
	typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::erase (const key_type& k)
	{
		iterator it = begin();
		while (it != end() && it->first != k) 	//ищем position
			it++;
		if (it == end())						//return если дошли до конца
			return(0);
		else if (it->first == k)				//если нашли нужный ключ, то удаляем его
			erase(it);
		return(1);//возвращает количество удаленных элементов
	}


	//erase(3)
	// Удаляет элементы в диапазоне [first; last)
	template <class Key, class T, class Compare, class Allocator>
	void map<Key, T, Compare, Allocator>::erase (iterator first, iterator last)
	{
		iterator it(first);
		iterator next;
		while (it != end() && it != last)
		{
			next = iterator(it.getPtr()->_next); 
			erase(it);
			it = next; //сдвигаем итератор на next
		}
	}

	//Заменяет содержимое контейнера содержимым x
	template <class Key, class T, class Compare, class Allocator>
	void map<Key, T, Compare, Allocator>::swap (map& x)
	{
		std::swap(_size, x._size);
		std::swap(_map, x._map);
	}


	// Удаляет все элементы из контейнера
	template <class Key, class T, class Compare, class Allocator>
	void map<Key, T, Compare, Allocator>::clear()
	{
		erase(begin(), end());
	}






	/*================================================================================*/
	/*-------------------------------------OBSERVERS----------------------------------*/
	/*================================================================================*/
	
	// возвращает функцию, сравнивающую ключи
	// возвращает true, если считается, что первый аргумент идет перед вторым и false в противном случае
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::key_compare map<Key, T, Compare, Allocator>::key_comp() const
	{
		return (_keycomp);
	}

	// возвращает функцию, которая сравнивает ключи в объектах типа value_type (псевдоним пары)
	// если первый аргумент меньше второго, то возвращае true, если элементы равны или первый аргумент больше второго, то возвращает false
	// https://www.cplusplus.com/reference/map/map/value_comp/
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::value_compare map<Key, T, Compare, Allocator>::value_comp() const
	{
		return (value_compare(_keycomp));
	}






	/*================================================================================*/
	/*-------------------------------------OPERATIONS---------------------------------*/
	/*================================================================================*/

	// Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает его итератор если он найден
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator		map<Key, T, Compare, Allocator>::find (const key_type& k)
	{
		iterator it = begin();
		while (it != end() && it->first != k)
			it++;
		return (it);
	}

	// Ищет в контейнере элемент с ключом, эквивалентным k, и возвращает его итератор если он найден
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::find (const key_type& k) const
	{
		const_iterator it = begin();
		while (it != end() && it->first != k)
			it++;
		return (it);				
	}

	// Ищет в контейнере элементы с ключом, эквивалентным k, и возвращает количество совпадений (0 или 1, так как все элементы уникальны)
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type		map<Key, T, Compare, Allocator>::count (const key_type& k) const
	{
		if (find(k) == end())
			return 0;
		else
			return 1;
	}

	// возвращает итератор на первый элемент не меньший, чем заданный ключ
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator		map<Key, T, Compare, Allocator>::lower_bound (const key_type& k)
	{
		iterator it = begin();
		while (it != end() && _keycomp(it->first, k))
			it++;
		return (it);
	}
	// возвращает итератор на первый элемент не меньший, чем заданный ключ
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::lower_bound (const key_type& k) const
	{
		const_iterator it = begin();
		while (it != end() && _keycomp(it->first, k))
			it++;
		return (it);				
	}

	// возвращает итератор на первый элемент больший, чем заданный ключ
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator		map<Key, T, Compare, Allocator>::upper_bound (const key_type& k)
	{
		iterator it = lower_bound(k);
		if (it->first == k)
			it++;
		return it;
	}

	// возвращает итератор на первый элемент больший, чем заданный ключ
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::upper_bound (const key_type& k) const
	{
		const_iterator it = lower_bound(k);
		if (it->first == k)
			it++;	//итерируем и возвращаем следующий элемент
		return it;
	}

	// возвращает диапазон элементов, соответствующих определённому ключу
	template <class Key, class T, class Compare, class Allocator>
	typename ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator>	map<Key, T, Compare, Allocator>::equal_range (const key_type& k) const
	{
		return(pair<iterator, iterator>(lower_bound(k),upper_bound(k)));
	}

	// возвращает диапазон элементов, соответствующих определённому ключу (возвращает всего один элемент, так как все ключи уникальны)
	template <class Key, class T, class Compare, class Allocator>
	typename ft::pair<typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator>	map<Key, T, Compare, Allocator>::equal_range (const key_type& k)
	{
		return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
	}







}; /***************************************************END: namespace ft **********/


#endif
