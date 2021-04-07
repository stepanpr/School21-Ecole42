#include "span.hpp"

// $> ./ex01
// 2
// 14
// $>

int main()
{
	srand(time(NULL));
	
	//SUBJECT
	std::cout << std::endl << "-------test-SUBJECT----" << std::endl;
	{	
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	//TEST1
	std::cout << std::endl << "-------test-1----------" << std::endl;
	{
		Span sp1 = Span(1);
		try
		{
			sp1.addNumber(33);
			sp1.addNumber(55);								//ошибка: поптыка записать слишком много значений
			sp1.addNumber(77);
		}
		catch(const std::exception& e)			
		{
			std::cerr << e.what() << '\n';
		}
		sp1.showValues();
		try
		{
			std::cout << sp1.shortestSpan() << std::endl; 	//ошибка: слишком мало значений в векторе	
			std::cout << sp1.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	//TEST2
	std::cout << std::endl << "-------test-2----------" << std::endl;
	{
		Span sp2 = Span(10000);
		try
		{
			sp2.addNumber(0, 10000);		//передаем диапазон int в addNumber
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		// sp2.showValues();				//показать значения вектора
	}

	//TEST3
	std::cout << std::endl << "-------test-3----------" << std::endl;
	{
		Span sp3(7);
		std::vector<int> vect(7);

		for(std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
			*it = rand() % 10;

		sp3.addNumber(vect);			//передаем вектор в addNumber
		sp3.showValues();				//показываем значения
		try
		{
			std::cout << sp3.shortestSpan() << std::endl;
			std::cout << sp3.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
