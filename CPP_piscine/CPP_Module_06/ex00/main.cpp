//
// CPP_Mod06_ex00/emabel/21school
//

#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <sstream>
#include <string>
#include <limits>
#include <math.h>

// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0

void	isChar(double num)
{
	std::cout << std::setw(10) << "char: ";
	if (std::isnan(num) )
		std::cout << "impossible" << std::endl;
	else if (num > 126 || num < 32)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
}

void	isInt(double num)
{
	std::cout << std::setw(10) << "int: ";
	if (num > INT_MAX || num < INT_MIN || std::isnan(num))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
}

void	isFloat(double num)
{
	std::cout << std::setw(10) << "float: ";
	if (num >= INFINITY || num <= -INFINITY)
	{
		std::cout << static_cast<float>(num) << "f" << std::endl;
		return ;
	}
	else
		std::cout << static_cast<float>(num) << "f" << std::endl;
}

void	isDouble(double num)
{
	std::cout << std::setw(10) << "double: ";
	if (num >= INFINITY || num <= -INFINITY)
	{
		std::cout << num << std::endl;
		return ;
	}
	else
		std::cout << num << std::endl;
}

int checkNanInf(std::string str)
{
	if (str != "+inf" && str != "-inf" && str != "inf" && str != "+inff" && str != "-inff" && str != "nan" && str != "nanf" && str != "inff")
		return 1;
	return 0;
}

int checkStr(std::string str)
{
	for(unsigned int i = 0; i < str.length(); i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != 'f' && str[i] != '.' && str[i] != '-' && str[i] != '+' && checkNanInf(str)) //если в числе есть символы отличные от f, '.', -, +
			return 1; 
	}
	return 0;
}

int	 main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string str(av[1]);
		if (strlen(av[1]) == 0)		//если аргумента пустой
			return(-1);
		if (strlen(av[1]) == 1 && av[1][0] >= 32 && (av[1][0] < '0' || av[1][0] > '9') && av[1][0] <= 126) //если подается символ
		{
			std::cout << std::setw(11) << "char: '" << av[1][0] << "'" << std::endl;
			std::cout << std::setw(10) << "int: " << static_cast<int>(av[1][0]) << std::endl;
			std::cout << std::setw(10) << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(av[1][0]) << "f" << std::endl;
			std::cout << std::setw(10) << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(av[1][0]) << std::endl; 
			exit(0);
		}
		if (checkStr(str))			//проверяем строку
			return(-1);
		else						//если подается число
		{
			std::cout.precision(1);
			std::cout.setf(std::ios::fixed);
			double num = std::stod(av[1]);	
			isChar(num);
			isInt(num);
			isFloat(num);
			isDouble(num);
		}
	}
	else
		std::cout << "Error: must be one argument (char / int / float / double)" << std::endl;
	return (0);
}
