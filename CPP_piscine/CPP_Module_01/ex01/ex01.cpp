
//
// CPP_Mod01_ex01/21school/emabel
//

#include <iostream>
#include <string>

void memoryLeak()
{
	std::string* panther = new std::string("String panther");
	std::cout << *panther << std::endl;
	delete(panther);                                             //очищаем выделенный участок памяти
}

int main (void)
{
	memoryLeak();
	// while (1)
	// 	;
	return (0);
}