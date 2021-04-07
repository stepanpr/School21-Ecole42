#include "iter.hpp"

int main()
{
	//CHAR
	std::cout << std::endl << "-------test-CHAR------" << std::endl;
	char array[9] = "21school";
	iter(array, 9, showValue);
	std::cout << std::endl;
	iter(array, 9, showValueWithSpace);
	std::cout << std::endl;

	//STRING
	std::cout << std::endl << "-------test-STRING----" << std::endl;
	std::string str[7] = {"string", "string", "string", "string", "string", "string", "string"};
	iter(str, 7, showValue);
	std::cout << std::endl;
	iter(str, 7, showValueWithSpace);
	std::cout << std::endl;

	//INT
	std::cout << std::endl << "-------test-INT-------" << std::endl;
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	iter(arr, 16, showValue);
	std::cout << std::endl;
	iter(arr, 16, showValueWithSpace);
	std::cout << std::endl;

	//CLASS AWESOME (from check list)
	std::cout << std::endl << "-------test-AWESOME---" << std::endl;
	{
		int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
		Awesome tab2[5];
		iter( tab, 5, print );
		iter( tab2, 5, print );
	}
	return (0);
}

