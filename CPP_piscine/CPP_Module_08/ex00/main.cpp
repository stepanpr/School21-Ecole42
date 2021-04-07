
#include "easyfind.hpp"


int main()
{
	//VECTOR
	std::cout << std::endl << "-------test-VECTOR----" << std::endl;
	{	
		std::vector<int> vect;
		for (int count = 0; count < 5; ++count)
			vect.push_back(count);
		try
		{
			std::cout << "result: " << easyfind(vect, 3) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "result: " << easyfind(vect, 21) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			for(int i = 0; i < 15; ++i)
				std::cout << "result: " << easyfind(vect, i) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	//LIST
	std::cout << std::endl << "-------test-LIST------" << std::endl;
	{	
		std::list<int> lst;
		for (int count = 0; count < 4; count++)
			lst.push_back(count);
		try
		{
			std::cout << "result: " << easyfind(lst, 5) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "result: " << easyfind(lst, 0) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			for(int i = 0; i < 100; ++i)
				std::cout << "result: " << easyfind(lst, i) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	//SET
	std::cout << std::endl << "-------test-SET-------" << std::endl;
	{	
		std::set<char> st;
		st.insert('b');
		st.insert('d');
		st.insert('a');
		st.insert('c');
		st.insert('e');
		try
		{
			std::cout << "result: " << static_cast<char>(easyfind(st, 'a')) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "result: " << static_cast<char>(easyfind(st, 'l')) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			for(int i = 0; i < 100; ++i)
				std::cout << "result: " << static_cast<char>(easyfind(st, 'a' + i)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}

