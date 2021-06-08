
//
// ft_containers/emabel/21school
//

#include "test.hpp"


int main(int argc, char **argv)
{
	std::string cmd;
	std::string request = "Please, enter your request...";
	std::string requestMsg1 = "Please, enter your request...";
	std::string requestMsg2 = "To test another contaiter, enter type of container (or \"exit\")...";
	int another = 0;

	std::cout << std::endl << std::endl <<PURPLE << "	┌─┐┌┬┐   ┌─┐┌─┐┌┐┌┌┬┐┌─┐┬┌┐┌┌─┐┬─┐┌─┐" << std::endl;
	std::cout << "	├┤  │    │  │ ││││ │ ├─┤││││├┤ ├┬┘└─┐" << std::endl;
	std::cout << "        └   ┴────└─┘└─┘┘└┘ ┴ ┴ ┴┴┘└┘└─┘┴└─└─┘" << std::endl;
	std::cout << GREEN << "                              𝕖𝕞𝕒𝕓𝕖𝕝/𝟚𝟙𝕤𝕔𝕙𝕠𝕠𝕝" << RESET << std::endl << std::endl;

	if (argc > 1) //если передаются аргументы
	{ 
		if (argc == 2)
		{
			std::string arg = static_cast<std::string>(argv[1]);
			if (arg == "vector")
				vectorTest();
			else if (arg == "list")
				listTest();
			else if (arg == "map")
				mapTest();
			else if (arg == "stack")
				stackTest();
			else if (arg == "queue")
				queueTest();
			else 
			{
				std::cout << YELLOW << "error: value is not valid" << RESET << std::endl;
				return (1);
			}
			std::cout << std::endl;
			return (0);
		}
		else if (argc > 2)
		{
			std::cout << YELLOW << "error: too much arguments" << RESET << std::endl;
			return (1);
		}
	}


	std::cout << "For start testing containers, please enter type of container: " 
	<< WHITE_B << "vector" << RESET << ", " << WHITE_B << "list" << RESET << ", " 
	<< WHITE_B << "map" << RESET << ", " << WHITE_B << "stack" << RESET << ", " 
	<< WHITE_B << "queue" << RESET << " (to close the program enter " << WHITE_B 
	<< "exit" << RESET <<")." << std::endl;

	while(1)
	{
		if (another == 1) 
		{ 	//если уже не первая итерация (another==1), то выводим enter()
			enter("press ENTER to continue");
			std::cout << request << std::endl;
		}
		getline(std::cin, cmd);
		if (cmd == "exit") { break; return(0); }
		if (cmd.length() > 0)
		{
			std::cout << "Your request is " << WHITE_B << cmd << RESET << std::endl;
		}
		else
		{
			std::cout << request << std::endl;
			another = 0;
			continue ;
		}
		enter("press ENTER to continue");
		if (cmd == "vector")
		{
			vectorTest();
			request = requestMsg2;
			another = 1;
			continue ;
		}
		if (cmd == "list")
		{
			listTest();
			request = requestMsg2;
			another = 1;
			continue ;
		}
		if (cmd == "map")
		{
			mapTest();
			request = requestMsg2;
			another = 1;
			continue ;
		}
		if (cmd == "stack")
		{
			stackTest();
			request = requestMsg2;
			another = 1;
			continue ;
		}
		if (cmd == "queue")
		{
			queueTest();
			request = requestMsg2;
			another = 1;
			continue ;
		}
		if (cmd == "exit") { break; return(0); }
		else 
		{
			std::cout << "Please, enter valid value (" << WHITE_B << "vector" 
			<< RESET << ", " << WHITE_B << "list" << RESET << ", " << WHITE_B 
			<< "map" << RESET << ", " << WHITE_B << "stack" << RESET ", " 
			<< WHITE_B << "queue" << RESET << " or " << WHITE_B << "exit" 
			<< RESET ")." << std::endl; //вы ввели некоректное значение, попробуйте снова (без цикла)
			another = 0;
			request = requestMsg1;
			continue ;
		}
	}
	return 0;
}
