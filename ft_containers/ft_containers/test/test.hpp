 
//
// ft_containers/emabel/21school
//

#ifndef TEST_HPP
# define TEST_HPP

# define RED  "\e[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"
# define RED_B "\033[1;31m"
# define GREEN_B "\033[1;32m"
# define YELLOW_B "\e[1;33m"
# define BLUE_B "\033[1;34m"
# define PURPLE_B "\033[1;35m"
# define CYAN_B "\e[1;36m"
# define WHITE_B "\e[1;37m"
# define RESET "\033[0m"

#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include "../includes/vector.hpp"
#include "../includes/list.hpp"
#include "../includes/map.hpp"
#include "../includes/stack.hpp"
#include "../includes/queue.hpp"


//вывод заголовка первого уровня
template<typename T>
void h1(T h1) 
{
	int len = static_cast<std::string>(h1).length();
	std::cout << std::endl << PURPLE_B << std::setfill('=') << std::setw(38 + (len/2)) << h1;
	std::cout << std::setfill('=') << std::setw(40 - (len/2))  << RESET << std::endl;

}

//вывод заголовка второго уровня
template<typename T>
void h2(T h2) 
{
	int len = static_cast<std::string>(h2).length();
	std::cout << std::endl << PURPLE_B << std::setfill('-') << std::setw(38 + (len/2)) << h2;
	std::cout << std::setfill('-') << std::setw(40 - (len/2))  << RESET << std::endl;
}

//enter для продолжения
template<typename M> 
void enter(M message)
{
	int i = -1;
	std::cout << std::setw(30) << std::endl << message << std::endl;
	while (1)
	{
		char str = std::cin.get();
		if (str == 0x0A)
			break ;
		++i;
	}
}

void vectorTest();
void listTest();
void mapTest();
void stackTest();
void queueTest();

#endif
