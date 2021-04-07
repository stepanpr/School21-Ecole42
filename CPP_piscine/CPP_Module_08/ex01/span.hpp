
//
// CPP_Mod08_ex01/emabel/21school
//

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <cstdlib>
# include <ctime>
# include <algorithm>
# include <iterator>


class Span
{
	private:
		unsigned int _N;						//максимальный размер вектора
		std::vector<int> _v;					//контейнер
		Span();
	public:
	
		/* canonical form */
		Span(unsigned int N);
		Span(const Span &copy);
   		Span &operator= (const Span &op);
		virtual ~Span();

		/* actions */
		void addNumber(unsigned int number);		//добавляем элемент в конец вектора
		int shortestSpan();							//возвращает самый короткий промежуток между числами 
		int longestSpan();							//возвращает самый длинный промежуток между числами


		void addNumber(int begin, int end);				//добавляем диапазон в конец вектора
		void addNumber(std::vector<int> const &vector); //добавляем вектор в конец вектора
		void showValues();

		/* exceptions */
		class isFull: public std::exception
		{
			virtual const char* what() const throw();
		};
		class tooSmall: public std::exception
		{
			virtual const char* what() const throw();
		};
		class errorValue: public std::exception
		{
			virtual const char* what() const throw();
		};
};



#endif
