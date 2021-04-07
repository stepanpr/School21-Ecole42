#include <iostream>
#include <string>

int main(void)
{
	//строка
	std::string brain = "HI THIS IS BRAIN";

	//указатель на строку
	std::string *brainPointer;
	brainPointer = &brain;
	std::cout << "  pointer: " << *brainPointer << std::endl;

	//ссылка на строку
	std::string &brainReference = brain;
	std::cout << "reference: " << brainReference << std::endl;

	return (0);
}
