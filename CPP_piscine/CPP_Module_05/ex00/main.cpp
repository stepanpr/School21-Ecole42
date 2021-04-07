
#include <iostream>
#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat predident("Mr. President", 1);
	std::cout << predident;
	Bureaucrat pablo("Pablo", 150);
	std::cout << pablo;

//------------------------------------------

	try //слишком низкий		 	
	{
		Bureaucrat Low("Low", 151);			
		std::cout << Low;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try	//слишком высокий									
	{
		Bureaucrat High("High", 0);
		std::cout << High;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

//------------------------------------------

		Bureaucrat decrement("decrement", 150);

	try //слишком низкий
	{
		std::cout << decrement;
		decrement.decrementGrade();
	
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << decrement;

	try //слишком высокий
	{
		Bureaucrat increment("increment", 1);
		std::cout << increment;
		increment.incrementGrade();
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}