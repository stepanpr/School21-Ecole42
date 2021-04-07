
#include "Array.hpp"

int main(void)
{
	std::srand(time(NULL));


	//CHAR
	std::cout << std::endl << "-------test-CHAR------" << std::endl;
	{
		Array<char> arr_char(26);
		for (unsigned int i = 0; i < arr_char.size(); i++)
			arr_char[i] = i + 97;
		for (unsigned int i = 0; i < arr_char.size(); i++)
			std::cout << arr_char[i] << ' ';
		std::cout << std::endl;
		try
		{
			for (unsigned int i = 0; i < 45; i++)
				std::cout << static_cast<char>(std::toupper(arr_char[i])) << ' '; //вывод с ошибкой, так как длина массива меньше 45
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			arr_char[100] = 'R';													//вывод с ошибкой
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}

	//STRING
	std::cout << std::endl << "-------test-STRING----" << std::endl;
	{
		Array<std::string> arr_string(7);
		std::string str = "21school";
		for (unsigned int i = 0; i < arr_string.size(); i++)
		{
			std::cout << i+1 << ". ";
			for (unsigned int j = 0; j < str.size(); j++)
			{
				arr_string[i].push_back(str[j]);
				
			}
			std::cout << arr_string[i] << std::endl;
		}
		try
		{
			arr_string[8];															//вывод с ошибкой - нету 8го индекса массива
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	//INT
	std::cout << std::endl << "-------test-INT-------" << std::endl;
	{
		Array<int> arr_int(43);
		for (unsigned int i = 0; i < arr_int.size(); i++)
			arr_int[i] = i;
		for (unsigned int i = 0; i < arr_int.size(); i++)
			std::cout << arr_int[i] << ' ';
		std::cout << std::endl;
		try
		{
			for (unsigned int i = 0; i < 45; i++)									//вывод с ошибкой, так как длина массива меньше 45
				std::cout << arr_int[i] << ' ';
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	//FLOAT
	std::cout << std::endl << "-------test-FLOAT-----" << std::endl;
	{
		Array<float> arr_float(7);
		for (unsigned int i = 0; i < arr_float.size(); i++)
			arr_float[i] = i + 0.7 / (rand() % 10);
		for (unsigned int i = 0; i < arr_float.size(); i++)
			std::cout << "["<< arr_float[i] << "] ";
		std::cout << std::endl;
		try
		{
			for (unsigned int i = 0; i < 10; i++)									//вывод с ошибкой, так как длина массива меньше 45
				std::cout << "["<< arr_float[i] << "] ";
		}
		catch(const std::exception& e)
		{
			std::cout  << e.what() << "]" << std::endl;
		}
	}

	//=
	std::cout << std::endl << "-------test-operator=-" << std::endl;
	{
		Array<char> arr_assign1(3);
		Array<char> arr_assign2(3);
		for (unsigned int i = 0; i < arr_assign1.size(); i++)
			arr_assign1[i] = i + 100;
		std::cout << "arr_assign1: ";
		for (unsigned int i = 0; i < arr_assign1.size(); i++)
			std::cout << "[" << arr_assign1[i] << "]";
		std::cout << std::endl;
		for (unsigned int i = 0; i < arr_assign2.size(); i++)
			arr_assign2[i] = i + 97;
		std::cout << "arr_assign2: ";
		for (unsigned int i = 0; i < arr_assign2.size(); i++)
			std::cout << "[" << arr_assign2[i] << "]";
		arr_assign1 = arr_assign2;														//присваиваем массиву 1 массив 2
		std::cout << std::endl;												
		std::cout << "arr_assign1 = arr_assign2 = ";
		for (unsigned int i = 0; i < arr_assign1.size(); i++)
			std::cout << "[" << arr_assign1[i] << "]";
		std::cout << std::endl;
		for (unsigned int i = 0; i < arr_assign2.size(); i++)							//перезаписывам массив 2
			arr_assign2[i] = i + 100;
		std::cout << "arr_assign2 after change values: ";
		for (unsigned int i = 0; i < arr_assign2.size(); i++)
			std::cout << "[" << arr_assign2[i] << "]";
		std::cout << std::endl;
		std::cout << "arr_assign1: ";
		for (unsigned int i = 0; i < arr_assign1.size(); i++)
			std::cout << "[" << arr_assign1[i] << "]";
		std::cout << std::endl;
		std::cout << "arr_assign2: ";
		for (unsigned int i = 0; i < arr_assign2.size(); i++)
			std::cout << "[" << arr_assign2[i] << "]";
		std::cout << std::endl;

		//()
		std::cout << std::endl << "-------test-copy()----" << std::endl;
		Array<char> arr_copy(arr_assign1);
		std::cout << "arr_copy(arr_assign1): ";
		for (unsigned int i = 0; i < arr_copy.size(); i++)								//записываем в новый массив arr_copy, массив arr_assign
			std::cout << "[" << arr_assign1[i] << "]";
		std::cout << std::endl;
	}

	return 0;
}