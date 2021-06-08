
#include "test.hpp"



//вывод значений векторов передаваемых в функцию
template < typename STDbegin, typename STDend,  typename FTbegin, typename FTend>
void printIterators(std::string const &msg, STDbegin std_begin, STDend std_end, FTbegin ft_begin, FTend ft_end) 
{
	{
		std::cout << msg << std::endl;
	}
	{
		std::cout << std::setfill(' ') << std::setw(10) << BLUE_B << "std [ " << BLUE;
		while (std_begin != std_end)
		{
			std::cout << std_begin->first << "==" << std_begin->second;
			std_begin++;
			if (std_begin == std_end)
			{
				std::cout << " ";
				break;
			}
			std::cout << ", ";

  		}
		std::cout << BLUE_B << "]" << RESET;

	}
	{
		std::cout << GREEN_B << " ft [ " << GREEN;
		while (ft_begin != ft_end) 
		{
			std::cout << ft_begin->first << "==" << ft_begin->second;
			ft_begin++;
			if (ft_begin == ft_end)
			{
				std::cout << " ";
				break;
			}
			std::cout << ", ";
  		}
		std::cout << GREEN_B << "]" << RESET << std::endl;
	}

}


//вывод значений вектора
template <typename Container>
void printContainer(Container &c)
{

	typename Container::iterator itBegin = c.begin();
  	typename Container::iterator itEnd = c.end();

	while (itBegin != itEnd) 
	{
		std::cout << itBegin->first << "==" << itBegin->second;
		++itBegin;
		if (itBegin == itEnd)
		{
			std::cout << " ";
			break;
		}
		std::cout << ", ";
	}
}
//вывод значений двух контейнеров std и ft
template <typename STDcontainer, typename FTcontainer>
void printValues(std::string const &msg, STDcontainer &ori_v, FTcontainer &my_v)
{
	{
		std::cout << msg << std::endl;
	}
	{
		{
			std::cout << std::setfill(' ') << std::setw(10) << std::right << BLUE_B << "std [ " << BLUE;
			printContainer(ori_v);
			std::cout << BLUE_B << "]" << RESET;

		}
		{
			std::cout  << GREEN_B << " ft [ " << GREEN;
			printContainer(my_v);
			std::cout << GREEN_B << "]" << RESET << std::endl;
		}
	}
}

//вывод значений контейнера и его методов size(), empty()
template<typename STDout, typename FTout>
void printCapacity(std::string const &msg, STDout &std, FTout &ft) 
{
	{
		std::cout << msg << std::endl;
	}
	{
		std::cout << std::setfill(' ') << std::setw(10) << BLUE_B << "std [ " << BLUE << "values: ";
		typename STDout::iterator itBegin = std.begin();
		typename STDout::iterator itEnd = std.end();


		while (itBegin != itEnd) 
		{
			std::cout << itBegin->first << "==" << itBegin->second;
			++itBegin;
			if (itBegin == itEnd)
			{
				std::cout << " ";
				break;
			}
			std::cout << ", ";
		}
		std::cout << "; size = " << std.size()
            << (std.empty() ? "; empty" : "; not empty");
		std::cout << BLUE_B << " ]" << RESET;

	}
	{
		std::cout << GREEN_B << " ft [ " << GREEN << "values: ";
		typename FTout::iterator itBegin = ft.begin();
		typename FTout::iterator itEnd = ft.end();

		while (itBegin != itEnd) 
		{
			std::cout << itBegin->first << "==" << itBegin->second;
			++itBegin;
			if (itBegin == itEnd)
			{
				std::cout << " ";
				break;
			}
			std::cout << ", ";
		}
		std::cout << "; size = " << ft.size()
            << (ft.empty() ? "; empty" : "; not empty");
		std::cout << GREEN_B << " ]" << RESET << std::endl;
	}
}


//вывод передаваемых значний областей STD и FT
template<typename STDout, typename FTout>
void printValue(std::string const &msg, STDout std, FTout ft) 
{
	{
		std::cout << msg << std::endl;
	}
	{
		std::cout << std::setfill(' ') << std::setw(10) << BLUE_B << "std [ " << BLUE << "value: ";
		std::cout << std;
		std::cout << BLUE_B << " ]" << RESET;

	}
	{
		std::cout << GREEN_B << " ft [ " << GREEN << "value: ";
		std::cout << ft;
		std::cout << GREEN_B << " ]" << RESET << std::endl;
	}
}




///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////




static void constructors() {

	h2("Constructors");
	/* default constructor */
	std::map<int, int> std_default;
	ft::map<int, int> ft_default;
	printValues("default constructor:", std_default, ft_default);

	/* range constructor */
	std::map<std::string, int> std_range;
	std_range["a"] = 10;
	std_range["b"] = 20;
	std_range["c"] = 21;
	std_range["d"] = 50;
	ft::map<std::string, int> ft_range;
	ft_range["a"] = 10;
	ft_range["b"] = 20;
	ft_range["c"] = 21;
	ft_range["d"] = 50;
	std::map<std::string, int> std_rangeconst (std_range.begin(), std_range.end());
	ft::map<std::string, int> ft_rangeconst (ft_range.begin(), ft_range.end());
	printValues("range constructor:", std_rangeconst, ft_rangeconst);

	/* copy constructor */
	std::map<std::string, int> std_copy(std_range);
	ft::map<std::string, int> ft_copy(ft_range);
	printValues("copy constructor (copy of range):", std_copy, ft_copy);

	/* assignation operator */
	std::map<std::string, int> std_assign;
	std_assign = std_copy;
	ft::map<std::string, int> ft_assign;
	ft_assign = ft_copy;
	printValues("assigment operator (assign = range):", std_assign, ft_assign);

}





static void iterators() 
{
	h2("Iterators");

	/* iterator */
	std::map<int, std::string> a;
	for (int i = 1; i < 8; ++i) 
		a.insert(std::pair<int, std::string>(i, "map"));
	std::map<int, std::string>::iterator std_beg = a.begin();
    std::map<int, std::string>::iterator std_end = a.end();
	
	ft::map<int, std::string> b;
	for (int i = 1; i < 8; ++i) 
		b.insert(ft::pair<int, std::string>(i, "map"));
	ft::map<int, std::string>::iterator ft_beg = b.begin();
    ft::map<int, std::string>::iterator ft_end = b.end();
	printIterators("iterator:", std_beg, std_end, ft_beg, ft_end);

	/* reverse iterator */
	std::map<int, std::string>::reverse_iterator std_rbeg = a.rbegin();
    std::map<int, std::string>::reverse_iterator std_rend = a.rend();
	ft::map<int, std::string>::reverse_iterator ft_rbeg = b.rbegin();
    ft::map<int, std::string>::reverse_iterator ft_rend = b.rend();
	printIterators("reverse iterator:", std_rbeg, std_rend, ft_rbeg, ft_rend) ;


	/* const iterator */
	const std::map<int, std::string> c(a);
	std::map<int, std::string>::const_iterator std_cbeg = c.begin();
	std::map<int, std::string>::const_iterator std_cend = c.end();
  	const ft::map<int, std::string> d(b);
	ft::map<int, std::string>::const_iterator ft_cbeg = d.begin();
	ft::map<int, std::string>::const_iterator ft_cend = d.end();
	printIterators("const iterator:", std_cbeg, std_cend, ft_cbeg, ft_cend) ;

	/* const reverse iterator */
	std::map<int, std::string>::const_reverse_iterator std_crbeg = c.rbegin();
	std::map<int, std::string>::const_reverse_iterator std_crend = c.rend();
	ft::map<int, std::string>::const_reverse_iterator ft_crbeg = d.rbegin();
	ft::map<int, std::string>::const_reverse_iterator ft_crend = d.rend();
	printIterators("const reverse iterator:", std_crbeg, std_crend, ft_crbeg, ft_crend) ;
}




static void capacity() 
{
	h2("Capacity");
	
	std::map<std::string, int> a;
	ft::map<std::string, int> b;
	printCapacity("CREATE containers \'std::a\' and \'ft::b\' (are emptys):", a, b);
	
	a.insert(std::pair<std::string, int>("school", 21));
	b.insert(ft::pair<std::string, int>("school", 21));
	printCapacity("containers \'std::a\' and \'ft::b\' after insert:", a, b);

	std::map<char, int> c;
	for(int i = 65; i < 70; i++)
		c[i] = i % 42;
	ft::map<char, int> d;
	for(int i = 65; i < 70; i++)
		d[i] = i % 42;
	printCapacity("CREATE containers \"std::c\" and \"ft::d\" (are not emptys):", c, d);

	/* max_size */
	printValue("\'c\' and \'d\' max_size():", c.max_size(), d.max_size());
}



static void element_access() 
{

  	h2("Element access");

	/* operator[] */
	std::map<std::string, int> std;
	std["AAA"] = 10;
	std["AAA"] = 70;  
	std["AAA"] = 100;    //пытаемся записать элементы с одинаковыми ключами несколько раз (запишется поледнее присваиваемое из значений)
	std["BBB"] = 200;
	std["BBB"] = 20000;
	std["CCC"] = 21;
	std["DDD"] = 500;
	ft::map<std::string, int> ft;
	ft["AAA"] = 10;
	ft["AAA"] = 70;
	ft["AAA"] = 100;
	ft["BBB"] = 200;
	ft["BBB"] = 20000;
	ft["CCC"] = 21;
	ft["DDD"] = 500;
	printValues("operator[]:", std, ft);

}



static void modifiers() 
{
	h2("Modifiers");

	/* insert: single element */
	std::map<int, std::string> std;
	ft::map<int, std::string> ft;
	std.insert(std::pair<int, std::string>(1, "one"));
	ft.insert(ft::pair<int, std::string>(1, "one"));
	printValues("insert (single element):", std, ft);	//one==1
	std.insert(std::pair<int, std::string>(2, "two"));
	ft.insert(ft::pair<int, std::string>(2, "two"));
	printValues("insert (single element):", std, ft);	//two==2
	std.insert(std::pair<int, std::string>(3, "three"));
	ft.insert(ft::pair<int, std::string>(3, "three"));
	printValues("insert (single element):", std, ft);	//three==3

	/* insert: with hint */
	std::map<int, std::string>::iterator it_std = ++std.begin();
	ft::map<int, std::string>::iterator it_ft = ++ft.begin();
	std.insert (it_std, std::pair<int, std::string>(21, "school"));
	ft.insert (it_ft, ft::pair<int, std::string>(21, "school"));
	printValues("insert (with hint):", std, ft);

	/*insert: range */
	std::map<int, std::string> std2;
	ft::map<int, std::string> ft2;
	std2.insert(std::pair<int, std::string>(0, "zero"));
	ft2.insert(ft::pair<int, std::string>(0, "zero"));
	std2.insert(std::pair<int, std::string>(4, "four"));
	ft2.insert(ft::pair<int, std::string>(4, "four"));
	std2.insert(std::pair<int, std::string>(5, "five"));
	ft2.insert(ft::pair<int, std::string>(5, "five"));
	std2.insert(std::pair<int, std::string>(6, "six"));
	ft2.insert(ft::pair<int, std::string>(6, "six"));
	std2.insert(std::pair<int, std::string>(7, "seven"));
	ft2.insert(ft::pair<int, std::string>(7, "seven"));
	std2.insert(std::pair<int, std::string>(100, "hundred"));
	ft2.insert(ft::pair<int, std::string>(100, "hundred"));
	printValues("CREATE news contriners STD2 and FT2:", std2, ft2);

	std2.insert(std.begin(), --std.end());	//от 1 до 3
	ft2.insert(ft.begin(), --ft.end());	
	printValues("insert (range):", std2, ft2);

	/* erase (iterator) */
	std2.erase(--std2.end());
	ft2.erase(--ft2.end());
	printValues("erase(--ft2.end()):", std2, ft2); //удаляем 100

	/* erase (key) */
	std2.erase(0);
	ft2.erase(0);
	printValues("erase(0):", std2, ft2); //удаляем 0

	/* erase (range) */
	std2.erase(std2.find(4), std2.end());
	ft2.erase(ft2.find(4), ft2.end());
	printValues("erase(ft2.find(4), ft2.end()):", std2, ft2); //удаляем диапазон 4 до конца

	/* swap */ 
	std::map<int, std::string> std3;
	ft::map<int, std::string> ft3;
	std3.insert(std::pair<int, std::string>(21, "school"));
	ft3.insert(ft::pair<int, std::string>(21, "school"));
	std3.insert(std::pair<int, std::string>(42, "ecole"));
	ft3.insert(ft::pair<int, std::string>(42, "ecole"));
	printValues("CREATE news contriners STD3 and FT3:", std3, ft3);
	std3.swap(std2);										//меняем местами значения ft2 и ft3
	ft3.swap(ft2);
	printValues("STD3 and FT3 after swap(ft2):", std3, ft3); 
	printValues("STD2 and FT2 after swap(ft2):", std2, ft2);

	/* clear */
	std3.clear();
	ft3.clear();
	printValues("STD3 and FT3 after clear():", std3, ft3); 
}



static void	observers()
{
	h2("Observers");

	/* key_comp */
	std::map<char,int> std;		//создаем исходные контейнеры
	ft::map<char,int> ft;
	std['a']=100;
	std['b']=200;
	std['c']=300;
	std['d']=400;
	ft['a']=100;
	ft['b']=200;
	ft['c']=300;
	ft['d']=400;
	printValues("CREATE contsiners STD and FT:", std, ft);

	std::map<char,int> std2;						//создаем контейнеры куда будем записывать значения при помощи компаратора
	ft::map<char,int> ft2;

	std::map<char,int>::key_compare key_comp_std = std.key_comp();	//объявляем переменную, хранящую ссылку на функцию key_comp(), 
	ft::map<char,int>::key_compare key_comp_ft = ft.key_comp();		//которая возвращает компаратор

  	char last_elem_std = std.rbegin()->first;     	//ключ последнего элемента
  	char last_elem_ft = ft.rbegin()->first;     	//ключ последнего элемента

	//std
  	std::map<char,int>::iterator it_std = std.begin();
	while (it_std != std.end())
	{														//записываем значения/пары из std в std2 до последнего 		
		if(key_comp_std((*it_std).first, last_elem_std))	//значения std (не включая его) используя компаратор
			std2.insert(*it_std);							//(вместо last_elem_std, можно использовать любое значение с 
		it_std++;											//которым мы будем сравнивать, например 'c')
	}	

	//ft												
	ft::map<char,int>::iterator it_ft = ft.begin();
	while (it_ft != ft.end())
	{														//записываем значения/пары из ft в ft2 до последнего 		
		if(key_comp_ft((*it_ft).first, last_elem_ft))		//значения ft (не включая его) используя компаратор
			ft2.insert(*it_ft);								//(вместо last_elem_ft, можно использовать любое значение с 
		it_ft++;											//которым мы будем сравнивать, например 'c')
	}
	printValues("STD2 and FT2 after copy values of STD and FT, using key_comp comparator:", std2, ft2);



	/* value_comp */
	std::map<char,int>::iterator it_std_a = std.find('a');		//создаем итераторы указывающие на ключи элементов, которые мы будем сравнивать
	ft::map<char,int>::iterator it_ft_a = ft.find('a');
  	std::map<char,int>::iterator it_std_b = std.find('b');
	ft::map<char,int>::iterator it_ft_b = ft.find('b');
	std::map<char,int>::iterator it_std_c = std.find('c');
	ft::map<char,int>::iterator it_ft_c = ft.find('c');
	std::map<char,int>::iterator it_std_d = std.find('d');
	ft::map<char,int>::iterator it_ft_d = ft.find('d');

	printValue("value_comp()(a, a):", std.value_comp()(*it_std_a, std::pair<char, int>('a', 21)), ft2.value_comp()(*it_ft_a, ft::pair<char, int>('a', 21))); // a == a, return 0
	printValue("value_comp()(b, c):", std.value_comp()(*it_std_b, std::pair<char, int>('c', 21)), ft2.value_comp()(*it_ft_b, ft::pair<char, int>('c', 21))); // b < c, return 1
	printValue("value_comp()(c, b):", std.value_comp()(*it_std_c, *it_std_b), ft2.value_comp()(*it_ft_c, *it_ft_b)); // c > b, return 0
	printValue("value_comp()(d, a):", std.value_comp()(*it_std_d, *it_std_a), ft2.value_comp()(*it_ft_d, *it_ft_a)); // d > a, return 0
	printValue("value_comp()(a, c):", std.value_comp()(*it_std_a, *it_std_c), ft2.value_comp()(*it_ft_a, *it_ft_c)); // a < c, return 1
}


static void	operations()
{
	h2("Operations");

	std::map<int, char> std;		//создаем исходные контейнеры
	ft::map<int, char> ft;
	for (int i = 1; i < 11; i++) 
	{
      	std[i] = i + 96;    
		ft[i] = i + 96;	  
	}
	printValues("CREATE containers STD and FT:", std, ft);

	/* find */
	printValue("find(7):", std.find(7)->second, ft.find(7)->second); // в find ищем 7 и от возвращаемого итератора передаем в printValue значение second
	printValue("find(5):", std.find(5)->second, ft.find(5)->second);
	printValue("find(10):", std.find(10)->second, ft.find(10)->second);
	/* count */
	printValue("count(7):", std.count(7), ft.count(7)); // смотрим присутсвует ли элемент с таким ключем (вервращает 0 или 1)
	printValue("count(1000):", std.count(1000), ft.count(1000));
	printValue("count(1):", std.count(1), ft.count(1));
	/* lower_bound */
	printValue("lower_bound(2):", std.lower_bound(2)->second, ft.lower_bound(2)->second); // возвращаем итератор на первый элемент, у которго ключ не меньший чем передаваемый в функцию
	printValue("lower_bound(6):", std.lower_bound(6)->second, ft.lower_bound(6)->second);
	printValue("lower_bound(4):", std.lower_bound(4)->second, ft.lower_bound(4)->second);
	/* upper_bound */
	printValue("upper_bound(6):", std.upper_bound(6)->second, ft.upper_bound(6)->second); // возвращаем итератор на первый элемент, у которго ключ больше чем передаваемый в функцию
	printValue("upper_bound(8):", std.upper_bound(8)->second, ft.upper_bound(8)->second);
	printValue("upper_bound(2):", std.upper_bound(2)->second, ft.upper_bound(2)->second);
	/* equal_range */
	printValue("equal_range (3):", std.equal_range(3).second->second, ft.equal_range(3).second->second); // возвращаем диапазон элементов соответствующих ключу k
	printValue("equal_range (6):", std.equal_range(5).second->second, ft.equal_range(5).second->second);
	printValue("equal_range (7):", std.equal_range(7).second->second, ft.equal_range(7).second->second);

}





void mapTest()
{
	h1("MAP");
  	constructors();
	enter("press ENTER to continue");
  	iterators();
	enter("press ENTER to continue");
  	capacity();
	enter("press ENTER to continue");
  	element_access();
	enter("press ENTER to continue");
 	modifiers();
	enter("press ENTER to continue");
	observers();
	enter("press ENTER to continue");
	operations();
}






























#include <map>
#include "test.hpp"

template<class Map>
void print(Map const &c) {
  typename Map::const_iterator b = c.begin();
  typename Map::const_iterator e = c.end();
  std::cout << "(size = " << c.size() << ", empty = " << (c.empty() ? "true" : "false") << ") ";
  while (b != e) {
    std::cout << "Key = \"" << b->first << "\", Value = \"" << b->second << "\" | ";
    ++b;
  }
  std::cout << "\n";
}

// void map_tests() {

//   title("MAP");
//   title("Constructors");
//   std::map<int, std::string> a;
//   for (int i = 0; i < 10; ++i) {
//     a.insert(std::make_pair(i, "test"));
//   }
//   std::map<int, std::string> b(a);
//   b.erase(b.begin());
//   b = a;
//   print(a);
//   print(b);
//   title("Iterators");
//   {
//     std::map<int, std::string>::iterator b = a.begin();
//     std::map<int, std::string>::iterator e = a.end();
//     while (b != e) {
//       std::cout << (*b).first << ", " << (*b).second << " ";
//       ++b;
//     }
//     std::cout << std::endl;
//   }
//   {
//     std::map<int, std::string>::reverse_iterator b = a.rbegin();
//     std::map<int, std::string>::reverse_iterator e = a.rend();
//     while (b != e) {
//       std::cout << (*b).first << ", " << (*b).second << " ";
//       ++b;
//     }
//     std::cout << std::endl;
//   }
//   title("Capacity");
//   a.clear();
//   print(a);
//   std::cout << "max_size = " << a.max_size() << std::endl;

//   title("Element access");
//   for (int i = 0; i < 10; ++i) {
//     a.insert(std::make_pair(i, "value" + std::string(1, i + '0')));
//   }
//   print(a);
//   std::cout << a[0] << std::endl;
//   a[0] = "hello";
//   std::cout << a[0] << std::endl;
//   a[20] = "bye";
//   print(a);
//   title("Insert");
//   std::cout << a.insert(std::make_pair(13, "New")).second << std::endl;
//   std::cout << a.insert(std::make_pair(13, "New")).second << std::endl;
//   a.insert(a.begin(), std::make_pair(13, "New"));
//   b.clear();
//   b.insert(a.begin(), a.end());
//   print(b);
//   title("Erase");
//   b.erase(b.begin());
//   print(b);
//   b.erase(13);
//   print(b);
//   b.erase(b.begin(), b.end());
//   print(b);
//   title("Swap");
//   a.swap(b);
//   print(a);
//   print(b);
//   title("Observers");
//   std::cout << a.key_comp()(1, 1) << std::endl;
//   std::cout << a.value_comp()(std::make_pair(1, "1"), std::make_pair(1, "2")) << std::endl;
//   title("Operations");
//   std::cout << b.find(1)->second << std::endl;
//   //std::cout << b.find(-1)->second << std::endl;

//   std::cout << b.count(1) << std::endl;
//   //std::cout << b.count(-1) << std::endl << std::endl;

//   std::cout << b.lower_bound(2)->second << std::endl;
// //  std::cout << b.lower_bound(40)->second << std::endl;

//   std::cout << b.upper_bound(1)->second << std::endl;
// //  std::cout << b.upper_bound(40)->second << std::endl;

//   std::cout << b.equal_range(1).first->second << std::endl;
//   std::cout << b.equal_range(1).second->second << std::endl;

// //  std::cout << b.equal_range(111).first->second << std::endl;
// //  std::cout << b.equal_range(111).second->second << std::endl;

// }