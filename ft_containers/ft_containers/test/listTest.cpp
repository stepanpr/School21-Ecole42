

#include "test.hpp"


//вывод значений векторов передаваемых в функцию
template < typename STDbegin, typename STDend,  typename FTbegin, typename FTend>
void printIterators(std::string const &msg, STDbegin begin, STDend end, FTbegin ftbegin, FTend ftend) 
{
	{
		std::cout << msg << std::endl;
	}
	{
		std::cout << std::setfill(' ') << std::setw(10) << BLUE_B << "std [ " << BLUE;
		while (begin != end) {
    		std::cout << *begin++ << " ";
  		}
		std::cout << BLUE_B << "]" << RESET;

	}
	{
		std::cout << GREEN_B << " ft [ " << GREEN;
		while (ftbegin != ftend) {
    		std::cout << *ftbegin++ << " ";
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
		std::cout << *itBegin << " ";
		++itBegin;
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
			std::cout << *itBegin << " ";
			++itBegin;
		}
		std::cout << ", size = " << std.size()
            << (std.empty() ? ", empty" : ", not empty");
		std::cout << BLUE_B << " ]" << RESET;

	}
	{
		std::cout << GREEN_B << " ft [ " << GREEN << "values: ";
		typename FTout::iterator itBegin = ft.begin();
		typename FTout::iterator itEnd = ft.end();

		while (itBegin != itEnd) {
			std::cout << *itBegin << " ";
			++itBegin;
		}
		std::cout << ", size = " << ft.size()
            << (ft.empty() ? ", empty" : ", not empty");
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


/* for remove_if */
bool    func_remif1(const int& val) { return (val <= 3); }
bool    func_remif2(const int& val) { return (val > 70 || val < 30); }
/* for unique */
bool    func_unique1(const int& a, const int& b) { return (a % 2 == 0 && b % 2 == 0); }
bool    func_unique2(const int& a, const int& b) { return (a == b);}
/* for sort */
bool    func_less(const int& a, const int& b) { return (a < b); }
bool    func_higher(const int& a, const int& b) { return (a > b); }






///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////




static void constructors() {

	h2("Constructors");

	std::list<int> std_defconst;
	ft::list<int> ft_defconst;
	printValues("default constructor:", std_defconst, ft_defconst);

	std::list<int> std_fillconst(5, 21);
	ft::list<int> ft_fillconst(5, 21);
	printValues("fill constructor:", std_fillconst, ft_fillconst);

	std::list<std::string> a(3, "list");							
	ft::list<std::string> b(3, "list");
	std::list<std::string> std_rangeconst(a.begin(), a.end());			//вызваем range-конструкторы с диапазоном от a и b
	ft::list<std::string> ft_rangeconst(b.begin(), b.end());
	printValues("range constructor:", std_rangeconst, ft_rangeconst);

	std::list<int> std_copyconst(std_fillconst);
	ft::list<int> ft_copyconst(ft_fillconst);
	printValues("copy constructor:", std_copyconst, ft_copyconst);

	std::list<std::string> std_assigm;
	ft::list<std::string> ft_assigm;
	std_assigm = std_rangeconst;
	ft_assigm = ft_rangeconst;
	printValues("assigment operator:", std_assigm, ft_assigm);
}





static void iterators() 
{

	h2("Iterators");

	/* iterator */
	std::list<int> a;
	for (int i = 0; i <= 10; ++i)
		a.push_back(i);
	std::list<int>::iterator std_begin = a.begin();
	std::list<int>::iterator std_end = a.end();
  	ft::list<int> b;
	for (int i = 0; i <= 10; ++i)
		b.push_back(i);
	ft::list<int>::iterator ft_begin = b.begin();
	ft::list<int>::iterator ft_end = b.end();
	printIterators("iterator:", std_begin, std_end, ft_begin, ft_end) ;

	/* reverse iterator */
	std::list<int>::reverse_iterator std_rbegin = a.rbegin();
	std::list<int>::reverse_iterator std_rend = a.rend();
	ft::list<int>::reverse_iterator ft_rbegin = b.rbegin();
	ft::list<int>::reverse_iterator ft_rend = b.rend();
	printIterators("reverse iterator:", std_rbegin, std_rend, ft_rbegin, ft_rend) ; 

	/* const iterator */
	const std::list<int> c(a);
	std::list<int>::const_iterator std_cbegin = c.begin();
	std::list<int>::const_iterator std_cend = c.end();
  	const ft::list<int> d(b);
	ft::list<int>::const_iterator ft_cbegin = d.begin();
	ft::list<int>::const_iterator ft_cend = d.end();
	printIterators("const iterator:", std_cbegin, std_cend, ft_cbegin, ft_cend) ;

	/* const reverse iterator */
	std::list<int>::const_reverse_iterator std_crbegin = c.rbegin();
	std::list<int>::const_reverse_iterator std_crend = c.rend();
	ft::list<int>::const_reverse_iterator ft_crbegin = d.rbegin();
	ft::list<int>::const_reverse_iterator ft_crend = d.rend();
	printIterators("const reverse iterator:", std_crbegin, std_crend, ft_crbegin, ft_crend) ;

}





static void capacity() 
{
	h2("Capacity");
	
	std::list<int> a;
	ft::list<int> b;
	printCapacity("CREATE containers \"std::a\" and \"ft::b\" (are emptys):", a, b);
	a.push_back(777);
	b.push_back(777);
	
	a.resize(7);
	b.resize(7);
	printCapacity("\"a\" and \"b\" after resize(7):", a, b);

	std::list<int> c(1, 21);
	ft::list<int> d(1, 21);
	printCapacity("CREATE containers \"std::c\"() and \"ft::d\" (are not emptys):", c, d);
	c.resize(3, 42);
	d.resize(3, 42);      //изменяет размер и заполняет пустые ноды (если такие есть) переданным значением
	printCapacity("\"c\" and \"d\" after resize(3, 111):", c, d); 

	printValue("\"c\" and \"d\" max_size():", c.max_size(), d.max_size());
}




static void element_access() 
{

  	h2("Element access");

  	std::list<int> a;					//заполняем значениями
  	for (int i = 1; i <= 10; i++)
		a.push_back(i);
  	ft::list<int> b;
  	for (int i = 1; i <= 10; i++)
		b.push_back(i);
	printCapacity("containers \"std::a\" and \"ft::b\":", a, b); //выводим параметры созданных контейнеров

	printValue("a.front() and b.front():", a.front(), b.front());
	printValue("a.back() and a.back():", a.back(), b.back());

}



static void modifiers() 
{
	h2("Modifiers");

	std::list<int> a(10, 777);
  	ft::list<int> b(10, 777);
	printValues("\"a\" and \"b\":", a, b);
	/* assign */
	a.assign(5, 21);
	b.assign(5, 21);
	printValues("\"a\" and \"b\" after asign(5, 21):", a, b);
	/* push_front */
	a.push_front(7777777);
	b.push_front(7777777);
	printValues("\"a\" and \"b\" after push_front(7777777):", a, b);
	/* pop_front */
	a.pop_front();
	b.pop_front();
	printValues("\"a\" and \"b\" after pop_front():", a, b);
	/* push_back */
	a.push_back(7777777);
	b.push_back(7777777);
	printValues("\"a\" and \"b\" after push_back(7777777):", a, b);
	/* pop_back */
	a.pop_back();
	b.pop_back();
	printValues("\"a\" and \"b\" after pop_back():", a, b);
	/* insert: single element */
	a.insert(a.begin(), 42);
	b.insert(b.begin(), 42);
	printValues("\"a\" and \"b\" after insert(a.begin(), 42):", a, b);
	/* insert: fill */
	a.insert(a.end(), 3, 42);
	b.insert(b.end(), 3, 42);
	printValues("\"a\" and \"b\" after insert(b.end(), 3, 42):", a, b);
	/*insert: range */
	std::list<int> c;
	ft::list<int> d;
	c.insert(c.begin(), ++a.begin(), --(--(--a.end()))); //записываем только значения 21
	d.insert(d.begin(), ++b.begin(), --(--(--b.end())));
	printValues("\"c\" and \"d\" after insert(x.begin(), ++y.begin(), --(--(--y.end())):", c, d);
	/* erase */
	a.erase(a.begin());
	b.erase(b.begin());  							//удаляем 42 из начала контейнеров "a" и "b"

	for (std::list<int>::iterator it = a.begin(); it != a.end();) //удаляем все значения 21 из контейнера "a"
	{
		*it == 21 ? it = a.erase(it) : ++it;
	}
	for (ft::list<int>::iterator it = b.begin(); it != b.end();) //удаляем все значения 21 из контейнера "b"
	{
		*it == 21 ? it = b.erase(it) : ++it;
	}
	printValues("\"a\" and \"b\" after erase(a.begin()):", a, b);

	/* swap */
	a.swap(c);
	b.swap(d);
	printValues("\"a\" and \"b\" after x.swap(y):", a, b);
	printValues("\"c\" and \"d\" after x.swap(y):", c, d);
	swap(a, c);
	ft::swap(b, d);
	printValues("\"a\" and \"b\" after swap(x, y):", a, b);
	printValues("\"c\" and \"d\" after swap(x, y):", c, d);
	/* clear */
	c.clear();
	d.clear();
	printValues("\"c\" and \"d\" after x.d.clear():", c, d);
}


static void	operations()
{
	h2("Operations");

	std::list<int> stdOne;
	std::list<int> stdTwo;
	ft::list<int> ftOne;
	ft::list<int> ftTwo;
	for(int i = 0; i < 10; i++)
	{
		stdOne.push_back(i);
		stdTwo.push_front(i * 10);
		ftOne.push_back(i);
		ftTwo.push_front(i * 10);
	}
	printValues("CREATE containers stdOne and ftOne:", stdOne, ftOne);
	printValues("CREATE containers stdTwo and ftTwo:", stdTwo, ftTwo);
	/* splice: entire list (1): переносим все элементы контейнера One на позицию begin() в Two */
	stdTwo.splice(stdTwo.begin(), stdOne);  		
	ftTwo.splice(ftTwo.begin(), ftOne);
	printValues("stdOne and ftOne after Two.splice(Two.begin(), One):", stdOne, ftOne);
	printValues("stdTwo and ftTwo after Two.splice(Two.begin(), One):", stdTwo, ftTwo);
	/* splice: single element (2): переносим один элемент begin() списка Two на позицию begin() списка One */
	stdOne.splice(stdOne.begin(), stdTwo, ++stdTwo.begin());
	ftOne.splice(ftOne.begin(), ftTwo, ++ftTwo.begin());
	printValues("stdOne and ftOne after One.splice(One.begin(), Two, ++Two.begin()):", stdOne, ftOne);
	printValues("stdTwo and ftTwo after One.splice(One.begin(), Two, ++Two.begin()):", stdTwo, ftTwo);
	/* splice: element range (3): переносим на позицию begin() списка One диапазон списка Two с begin() по ++(++begin()) в цикле (по 2 элемента) */
	for (int i = 0; i < 4; i++)
	{
		stdOne.splice(stdOne.begin(), stdTwo, stdTwo.begin(), ++(++stdTwo.begin()));
		ftOne.splice(ftOne.begin(), ftTwo, ftTwo.begin(), ++(++ftTwo.begin()));
	}
	printValues("stdOne and ftOne after One.splice(One.begin(), Two, ++Two.begin()):", stdOne, ftOne);
	printValues("stdTwo and ftTwo after One.splice(One.begin(), Two, ++Two.begin()):", stdTwo, ftTwo);

	/* remove */
	stdTwo.remove(9);
	stdTwo.remove(0);
	ftTwo.remove(9);
	ftTwo.remove(0);
	printValues("stdTwo and ftTwo after remove(9 and 0):", stdTwo, ftTwo);


	/* remove_if: применяем функцию для удаления значений если функция возвращает true */
	stdOne.remove_if(func_remif1);
	stdTwo.remove_if(func_remif2);
	ftOne.remove_if(func_remif1);
	ftTwo.remove_if(func_remif2);
	printValues("stdOne and ftOne after remove_if(func_remif1):", stdOne, ftOne);	//return (val <= 3)
	printValues("stdTwo and ftTwo after remove_if(func_remif2):", stdTwo, ftTwo); 	//return (val > 70 || val < 30)

	/* unique (1) удаляем все элементы, кроме первого из каждой последующей группы одинаковых элементов в контейнере */
	std::list<int> stdThree;
	ft::list<int> ftThree;
	for(int i = 0; i < 10; i++)
	{
		stdThree.push_front(i);
		stdThree.push_front(i);
		stdThree.push_front(i);
		ftThree.push_front(i);
		ftThree.push_front(i);
		ftThree.push_front(i);
	}
	printValues("CREATE containers stdThree and ftThree:", stdThree, ftThree);

	stdThree.unique();
	ftThree.unique();
	printValues("stdThree and ftThree after unique():", stdThree, ftThree);

	/* unique (2) удаляем все элементы, кроме первого из каждой последующей группы одинаковых 
	элементов в контейнере, если функция сравнения возвращает true */
	stdThree.clear();
	ftThree.clear();
	for(int i = 1; i <= 3; i++)
	{
		stdThree.push_front(i);
		stdThree.push_front(i);
		stdThree.push_front(i);
		ftThree.push_front(i);
		ftThree.push_front(i);
		ftThree.push_front(i);
	}
	printValues("CHANGE containers stdThree and ftThree:", stdThree, ftThree);
	
	stdThree.unique(func_unique1);
	ftThree.unique(func_unique1); //удаляется повтор двойки
	printValues("stdThree and ftThree after unique(func_unique1):", stdThree, ftThree); //return (a % 2 == 0 && b % 2 == 0)

	stdThree.unique(func_unique2);
	ftThree.unique(func_unique2); //удаляется повтор всех чисел
	printValues("stdThree and ftThree after unique(func_unique2):", stdThree, ftThree); //return (a == b)

	/* merge (1): слияние двух списков */
	stdOne.merge(stdTwo);
	ftOne.merge(ftTwo);
	printValues("stdOne and ftOne after One.merge(Two):", stdOne, ftOne);

	/* merge (2): слияние двух списков, принимает сравнивающую функцию */
	stdOne.merge(stdThree, func_less);
	ftOne.merge(ftThree, func_less);  //3 2 1 + 7 8 5 6 4 70 60 50 40 30
	printValues("stdOne and ftOne after One.merge(Three, func_less):", stdOne, ftOne);  //return (a < b);


	/* sort (1): сортировка*/
	stdOne.sort();
	ftOne.sort();
	printValues("stdOne and ftOne after One.sort():", stdOne, ftOne);

	/* sort (1): сортировка с компаратором возвращающим bool*/
	// stdOne.sort([](int a, int b) {return a > b; });
	// ftOne.sort([](int& a, int& b) { return a > b; });
	stdOne.sort(func_higher);
	ftOne.sort(func_higher);
	printValues("stdOne and ftOne after One.sort(func_higher):", stdOne, ftOne);


	stdOne.reverse();
	ftOne.reverse();
	printValues("stdOne and ftOne after One.reverse():", stdOne, ftOne);
}




static void relational_operators() 
{
	h2("Relational operators");

	std::list<int> std_a;
	std::list<int> std_b;
	ft::list<int> ft_c;
	ft::list<int> ft_d;
	for(int i = 0; i < 10; i++)
	{
		std_a.push_back(i);
		std_b.push_back(i);
		ft_c.push_back(i);
		ft_d.push_back(i);
	}
	printValues("CREATE - \"std_a\" and \"ft_c\"", std_a, ft_c);
	printValues("CREATE - \"std_b\" and \"ft_d\"", std_b, ft_d);
	printValue("a == b; c == d", std_a == std_b, ft_c == ft_d);
	printValue("a != b; c != d", std_a != std_b, ft_c != ft_d);
	printValue("a < b; c < d", std_a < std_b, ft_c < ft_d);
	printValue("a <= b; c <= d", std_a <= std_b, ft_c <= ft_d);
	printValue("a > b; c > d", std_a > std_b, ft_c > ft_d);
	printValue("a >= b; c >= d", std_a >= std_b, ft_c >= ft_d);

	std_a.pop_back();
	ft_c.pop_back();
	printValues("CHANGE - pop_back() for \"std_a\" and \"ft_c\"", std_a, ft_c);
	printValue("a == b; c == d", std_a == std_b, ft_c == ft_d);
	printValue("a != b; c != d", std_a != std_b, ft_c != ft_d);
	printValue("a < b; c < d", std_a < std_b, ft_c < ft_d);
	printValue("a <= b; c <= d", std_a <= std_b, ft_c <= ft_d);
	printValue("a > b; c > d", std_a > std_b, ft_c > ft_d);
	printValue("a >= b; c >= d", std_a >= std_b, ft_c >= ft_d);

	std::list<std::string> str1(3, "list");
	std::list<std::string> str2;
	ft::list<std::string> str3(3, "list");
	ft::list<std::string> str4;
	printValues("CREATE - \"std str1\" and \"ft str3\"", str1, str3);
	printValues("CREATE - \"std str2\" and \"ft str4\"", str2, str4);

	printValue("str1 == str2; str3 == str4", str1 == str2 ? "true" : "false", str3 == str4 ? "true" : "false");
	printValue("str1 != str2; str3 != str4", str1 != str2 ? "true" : "false", str3 != str4 ? "true" : "false");
	printValue("str1 < str2; str3 < str4", str1 < str2 ? "true" : "false", str3 < str4 ? "true" : "false");
	printValue("str1 <= str2; str3 <= str4", str1 <= str2 ? "true" : "false", str3 <= str4 ? "true" : "false");
	printValue("str1 > str2; str3 > str4", str1 > str2 ? "true" : "false", str3 > str4 ? "true" : "false");
	printValue("str1 >= str2; str3 >= str4", str1 >= str2 ? "true" : "false", str3 >= str4 ? "true" : "false");
}



void listTest()
{
	h1("LIST");
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
	operations();
	enter("press ENTER to continue");
  	relational_operators();
}
