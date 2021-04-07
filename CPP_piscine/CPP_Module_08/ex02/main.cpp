
#include "mutantstack.hpp"

int main()
{
	{	
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}


	//TEST1
	std::cout << std::endl << "-------test-1----------" << std::endl;
	{
		MutantStack<int> stack1;
		stack1.push(21);
		stack1.push(1);
		stack1.push(2);
		stack1.push(3);
		stack1.push(4);
		stack1.push(5);

		std::cout << "size of stack1: " << stack1.size() << std::endl;     	//проверяем размер (6)
		std::cout << " top of stack1: " << stack1.top() << std::endl;		//проверяем верхний элемент (5)
		MutantStack<int>::iterator it = stack1.begin();
		it++;																//сдвигаем итератор с первого на второе значение
		while (it != stack1.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
		stack1.pop();														//удаляем 5 "верхних" элементов
		stack1.pop();
		stack1.pop();
		stack1.pop();
		stack1.pop();
		std::stack<int> NEWstack1(stack1);									   //применяем оператор копирования в NEWstack1 (базовый std::stack)
		std::cout << "size of NEWstack1: " << NEWstack1.size() << std::endl;   //проверяем размер (1)
		std::cout << " top of NEWstack1: " << NEWstack1.top() << std::endl;	   //проверяем верхний элемент (21)
	}


	//TEST2
	std::cout << std::endl << "-------test-2----------" << std::endl;
	{
		MutantStack<std::string> stack2;
		std::string str[3] = {"sch", "ool", "21"};
								
		for (size_t i = 0; i < 3; i++)						//записываем в стек значения из массива строк
			stack2.push(str[i]);

		std::cout << "size of stack2: " << stack2.size() << std::endl;	//смотрим размер стека (3)
		std::cout << " top of stack2: " << stack2.top() << std::endl << std::endl;	//проверяем верхний элемент (21)

		for(MutantStack<std::string>::iterator it = stack2.begin(); it != stack2.end(); it++)	//выводим значения стека
			std::cout << *it << std::endl;
		std::cout << std::endl;

		MutantStack<std::string> NEWstack2 = stack2;		//применяем оператор присваивания к NEWstack2

		NEWstack2.push(" is");								//добавляем значения
		NEWstack2.push(" the");
		NEWstack2.push(" best");
		NEWstack2.push(" school");

		for(MutantStack<std::string>::iterator it = NEWstack2.begin(); it != NEWstack2.end(); it++)	//выводим значения стека
			std::cout << *it;
		std::cout << std::endl <<std::endl;

		std::cout << "size of NEWstack1: " << NEWstack2.size() << std::endl;   //проверяем размер (7)
		std::cout << " top of NEWstack1: " << NEWstack2.top() << std::endl;	   //проверяем верхний элемент ( school)
	}


	return 0;
}
