

#include "test.hpp"


//вывод значений
//если передавать контейнер по ссылке &, то его значения удалятся после вывода
template <typename Container>
void printContainer(Container c) 
{
	while (!c.empty()) 
	{

	std::cout  << c.front();
	c.pop();
		if (c.size())
			std::cout << ", ";
		else
		{
			std::cout << " ";
			break;
		}
    }
}

//вывод значений двух контейнеров std и ft
template <typename STDcontainer, typename FTcontainer>
void printValues(std::string const &msg, STDcontainer &std, FTcontainer &ft)
{
	{
		std::cout << msg << std::endl;
	}
	{
		{
			std::cout << std::setfill(' ') << std::setw(10) << std::right << BLUE_B << "std [ " << BLUE;
			printContainer(std);
			std::cout << BLUE_B << "]" << RESET;

		}
		{
			std::cout  << GREEN_B << " ft [ " << GREEN;
			printContainer(ft);
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
		printContainer(std);
		std::cout << "; size = " << std.size() << (std.empty() ? "; empty" : "; not empty");
		std::cout << BLUE_B << " ]" << RESET;

	}
	{
		std::cout << GREEN_B << " ft [ " << GREEN << "values: ";
		printContainer(ft);
		std::cout << "; size = " << ft.size() << (ft.empty() ? "; empty" : "; not empty");
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

	h2("Constructor");

	std::queue<int> std_default;
	ft::queue<int> ft_default; 
	printCapacity("empty container:", std_default, ft_default);

	std::list<int>	std_lst;
	ft::list<int>	ft_lst;
	std_lst.push_back(111);
	std_lst.push_back(222);
	std_lst.push_back(333);
	ft_lst.push_back(111);
	ft_lst.push_back(222);
	ft_lst.push_back(333);

	std::queue<int, std::list<int> >	std_copy(std_lst);
	ft::queue<int, ft::list<int> >		ft_copy(ft_lst);
	printCapacity("queue with list as underlying container:", std_copy, ft_copy);
}

static void member_functions() {

	h2("Member functios");

	std::queue<int> std;
	ft::queue<int> ft;

	std.push(1);
	std.push(2);
	std.push(3);
	std.push(4);
	std.push(5);
	std.push(6);
	std.push(7);
	ft.push(1);
	ft.push(2);
	ft.push(3);
	ft.push(4);
	ft.push(5);
	ft.push(6);
	ft.push(7);
	printCapacity("STD and FT containers:", std, ft);
	printValue("front():", std.front(), ft.front());
	printValue("back():", std.back(), ft.back());

	std.pop();
	ft.pop();
	printCapacity("containers after pop():", std, ft);

	while (!std.empty())
	{
		std.pop();
	}
	while (!ft.empty())
	{
		ft.pop();
	}
	printCapacity("containers after pop() in cycle:", std, ft);
	

}

static void  non_member_function_overloads()
{

	h2("Non-member function overloads");

	std::queue<int> std_a;
	std::queue<int> std_b;
	ft::queue<int> ft_c;
	ft::queue<int> ft_d;

	for(int i = 0; i < 10; i++)
	{
		std_a.push(i);
		std_b.push(i);
		ft_c.push(i);
		ft_d.push(i);
	}

	printValues("CREATE - \"std_a\" and \"ft_c\"", std_a, ft_c);
	printValues("CREATE - \"std_b\" and \"ft_d\"", std_b, ft_d);
	printValue("a == b; c == d", std_a == std_b, ft_c == ft_d);
	printValue("a != b; c != d", std_a != std_b, ft_c != ft_d);
	printValue("a < b; c < d", std_a < std_b, ft_c < ft_d);
	printValue("a <= b; c <= d", std_a <= std_b, ft_c <= ft_d);
	printValue("a > b; c > d", std_a > std_b, ft_c > ft_d);
	printValue("a >= b; c >= d", std_a >= std_b, ft_c >= ft_d);

	std_a.pop();
	ft_c.pop();
	printValues("CHANGE - pop() for \"std_a\" and \"ft_c\"", std_a, ft_c);
	printValue("a == b; c == d", std_a == std_b, ft_c == ft_d);
	printValue("a != b; c != d", std_a != std_b, ft_c != ft_d);
	printValue("a < b; c < d", std_a < std_b, ft_c < ft_d);
	printValue("a <= b; c <= d", std_a <= std_b, ft_c <= ft_d);
	printValue("a > b; c > d", std_a > std_b, ft_c > ft_d);
	printValue("a >= b; c >= d", std_a >= std_b, ft_c >= ft_d);


}


void queueTest()
{
	h1("QUEUE");
  	constructors();
	enter("press ENTER to continue");
  	member_functions();
	enter("press ENTER to continue");
  	non_member_function_overloads();
	// enter("press ENTER to continue");
}
