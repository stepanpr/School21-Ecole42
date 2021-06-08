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
	typedef typename Container::size_type type;
	for (type i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
}


//вывод значений двух контейнеров std и ft
template <typename stdVector, typename ftVector>
void printValues(std::string const &msg, stdVector &ori_v, ftVector &my_v)
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

//вывод значений контейнера и его методов size(), capacity(), empty()
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
		std::cout << ", size = " << std.size() << ", capacity = " << std.capacity()
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
		std::cout << ", size = " << ft.size() << ", capacity = " << ft.capacity()
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


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


static void constructors() {

	h2("Constructors");

	std::vector<int> std_defconst;
	ft::vector<int> ft_defconst;
	printValues("default constructor:", std_defconst, ft_defconst);

	std::vector<int> std_fillconst(5, 21);
	ft::vector<int> ft_fillconst(5, 21);
	printValues("fill constructor:", std_fillconst, ft_fillconst);

	std::vector<std::string> a(3, "vector");							
	ft::vector<std::string> b(3, "vector");
	std::vector<std::string> std_rangeconst(a.begin(), a.end());			//вызваем range-конструкторы с диапазоном от a и b
	ft::vector<std::string> ft_rangeconst(b.begin(), b.end());
	printValues("range constructor:", std_rangeconst, ft_rangeconst);

	std::vector<int> std_copyconst(std_fillconst);
	ft::vector<int> ft_copyconst(ft_fillconst);
	printValues("copy constructor:", std_copyconst, ft_copyconst);

	std::vector<std::string> std_assigm;
	ft::vector<std::string> ft_assigm;
	std_assigm = std_rangeconst;
	ft_assigm = ft_rangeconst;
	printValues("assigment operator:", std_assigm, ft_assigm);

}





static void iterators() 
{

	h2("Iterators");

	/* iterator */
	std::vector<int> a;
	for (int i = 0; i <= 10; ++i)
		a.push_back(i);
	std::vector<int>::iterator std_begin = a.begin();
	std::vector<int>::iterator std_end = a.end();
  	ft::vector<int> b;
	for (int i = 0; i <= 10; ++i)
		b.push_back(i);
	ft::vector<int>::iterator ft_begin = b.begin();
	ft::vector<int>::iterator ft_end = b.end();
	printIterators("iterator:", std_begin, std_end, ft_begin, ft_end) ;

	/* reverse iterator */
	std::vector<int>::reverse_iterator std_rbegin = a.rbegin();
	std::vector<int>::reverse_iterator std_rend = a.rend();
	ft::vector<int>::reverse_iterator ft_rbegin = b.rbegin();
	ft::vector<int>::reverse_iterator ft_rend = b.rend();
	printIterators("reverse iterator:", std_rbegin, std_rend, ft_rbegin, ft_rend) ; 

	/* const iterator */
	const std::vector<int> c(a);
	std::vector<int>::const_iterator std_cbegin = c.begin();
	std::vector<int>::const_iterator std_cend = c.end();
  	const ft::vector<int> d(b);
	ft::vector<int>::const_iterator ft_cbegin = d.begin();
	ft::vector<int>::const_iterator ft_cend = d.end();
	printIterators("const iterator:", std_cbegin, std_cend, ft_cbegin, ft_cend) ;

	/* const reverse iterator */
	std::vector<int>::const_reverse_iterator std_crbegin = c.rbegin();
	std::vector<int>::const_reverse_iterator std_crend = c.rend();
	ft::vector<int>::const_reverse_iterator ft_crbegin = d.rbegin();
	ft::vector<int>::const_reverse_iterator ft_crend = d.rend();
	printIterators("const reverse iterator:", std_crbegin, std_crend, ft_crbegin, ft_crend) ;

}





static void capacity() 
{
	h2("CAPACITY");
	
	std::vector<int> a;
	ft::vector<int> b;
	printCapacity("containers \"a\" and \"b\" are emptys:", a, b);
	a.reserve(21);
	b.reserve(21);
	printCapacity("\"a\" and \"b\" after reserve(21):", a, b);
	a.resize(7);
	b.resize(7);
	printCapacity("\"a\" and \"b\" after resize(7):", a, b);

	std::vector<int> c;
	ft::vector<int> d;
	c.resize(3, 111);
	d.resize(3, 111);
	printCapacity("\"c\" and \"d\" after resize(3, 111):", c, d);
	c.reserve(100);
	d.reserve(100);
	printCapacity("\"c\" and \"d\" after reserve(100):", c, d);
	printValue("\"c\" and \"d\" max_size():", c.max_size(), d.max_size());

	
}




static void element_access() 
{

  	h2("ELEMENT ACCESS");

  	std::vector<int> a;					//заполняем значениями
  	for (int i = 1; i <= 10; i++)
		a.push_back(i);
  	ft::vector<int> b;
  	for (int i = 1; i <= 10; i++)
		b.push_back(i);
	printCapacity("containers \"std::a\" and \"ft::b\":", a, b); //выводим параметры созданных контейнеров

	/* оператор [] */ 
	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;
	std::cout << "a[3] = " << a[3] << std::endl;
	std::cout << "b[3] = " << b[3] << std::endl;

	a[7] = 21;
	b[7] = 21;
	std::cout << "a[7] after change value = " << a[7] << std::endl;
	std::cout << "b[7] after change value = " << b[7] << std::endl;

   	/* at() */ 
	try {
		std::cout << "a.at(7) = " << a.at(7) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "b.at(7) = " << b.at(7) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "a.front() = " << a.front() << std::endl; //прямая ссылка на первый и последний элементы
	std::cout << "a.back() = " << a.back() << std::endl;
	std::cout << "b.front() = " << b.front() << std::endl;
	std::cout << "b.back() = " << b.back() << std::endl;
}





static void modifiers() 
{
	h2("Modifiers");

	std::vector<int> a(10, 777);
  	ft::vector<int> b(10, 777);
	printValues("\"a\" and \"b\":", a, b);
	/* assign */
	a.assign(5, 21);
	b.assign(5, 21);
	printValues("\"a\" and \"b\" after asign(5, 21):", a, b);
	/*push_back */
	a.push_back(777);
	b.push_back(777);
	printValues("\"a\" and \"b\" after push_back(777):", a, b);
	/*pop_back */
	a.pop_back();
	b.pop_back();
	printValues("\"a\" and \"b\" after pop_back():", a, b);
	/*insert: single element */
	a.insert(a.begin(), 42);
	b.insert(b.begin(), 42);
	printValues("\"a\" and \"b\" after insert(a.begin(), 42):", a, b);
	/*insert: fill */
	a.insert(a.end(), 3, 42);
	b.insert(b.end(), 3, 42);
	printValues("\"a\" and \"b\" after insert(b.end(), 3, 42):", a, b);
	/*insert: range */
	std::vector<int> c;
	ft::vector<int> d;
	c.insert(c.begin(), ++a.begin(), --(--(--a.end()))); //записываем только значения 21
	d.insert(d.begin(), ++b.begin(), --(--(--b.end())));
	printValues("\"c\" and \"d\" after insert(x.begin(), ++y.begin(), --(--(--y.end())):", c, d);
	/* erase */
	a.erase(a.begin());
	b.erase(b.begin());  							//удаляем 42 из начала контейнера

	for (std::vector<int>::iterator it = a.begin(); it != a.end();) //удаляем все значения 21 из контейнера "a"
	{
		if (*it == 21)
			a.erase(it);
		else
			++it;
	}
	for (ft::vector<int>::iterator it = b.begin(); it != b.end();) //удаляем все значения 21 из контейнера "b"
	{
		if (*it == 21)
			b.erase(it);
		else
			++it;
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




static void relational_operators() 
{
	h2("Relational operators");

	std::vector<int> std_a;
	std::vector<int> std_b;
	ft::vector<int> ft_c;
	ft::vector<int> ft_d;
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

	std::vector<std::string> str1(3, "vector");
	std::vector<std::string> str2;
	ft::vector<std::string> str3(3, "vector");
	ft::vector<std::string> str4;
	printValues("CREATE - \"std str1\" and \"ft str3\"", str1, str3);
	printValues("CREATE - \"std str2\" and \"ft str4\"", str2, str4);

	printValue("str1 == str2; str3 == str4", str1 == str2 ? "true" : "false", str3 == str4 ? "true" : "false");
	printValue("str1 != str2; str3 != str4", str1 != str2 ? "true" : "false", str3 != str4 ? "true" : "false");
	printValue("str1 < str2; str3 < str4", str1 < str2 ? "true" : "false", str3 < str4 ? "true" : "false");
	printValue("str1 <= str2; str3 <= str4", str1 <= str2 ? "true" : "false", str3 <= str4 ? "true" : "false");
	printValue("str1 > str2; str3 > str4", str1 > str2 ? "true" : "false", str3 > str4 ? "true" : "false");
	printValue("str1 >= str2; str3 >= str4", str1 >= str2 ? "true" : "false", str3 >= str4 ? "true" : "false");
}



void vectorTest() 
{
	h1("VECTOR");
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
  	relational_operators();
}
