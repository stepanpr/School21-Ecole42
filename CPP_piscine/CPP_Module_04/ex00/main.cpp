#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Victim.hpp"
#include "Doctor.hpp"


// Robert, the Magnificent, is born!$
// Some random victim called Jimmy just appeared!$
// Some random victim called Joe just appeared!$
// Zog zog.$
// I am Robert, the Magnificent, and I like ponies!$
// I'm Jimmy and I like otters!$
// I'm Joe and I like otters!$
// Jimmy has been turned into a cute little sheep!$
// Joe has been turned into a pink pony!$
// Bleuark...$
// Victim Joe just died for no apparent reason!$
// Victim Jimmy just died for no apparent reason!$
// Robert, the Magnificent, is dead. Consequences will never be the same!$

int main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim jim("Jimmy");
		Peon joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}


	// Peon zero; 							//error

	// Peon first("firstPeon");
	// Peon firstNew("NoName");
	// firstNew = first;					//вызываем оператор присваивания
	// std::cout << firstNew.getName() 
	// << std::endl;

	// Peon second("secondPeon");			//копирование
	// Peon secondNew(second);				

	// Victim *doc = new Doctor("Doc");		//new Doctor
	// doc->getPolymorphed();
	// delete(doc);

	// Doctor doct("Doctor");				//присваивание классу Victim класс Doctor
	// std::cout << doct;
	// Victim& victim = doct;
	// victim.getPolymorphed();
	return 0;
}





// 	// std::cout << std::endl << std::endl;
// 	// Peon hello("hello");
// 	// Peon bye(hello);
// 	// Peon maxi("maxy");
// 	// std::cout << std::endl << std::endl;
// 	// std::cout << hello << bye << maxi;
// 	// std::cout << std::endl << std::endl;
// 	// bye = maxi;
// 	// std::cout << hello << bye << maxi;
// 	// std::cout << std::endl << std::endl;

// 	// Sorcerer scopycat("Scopycat", "pfpfpfpf pf");
// 	// Sorcerer king("king", "yoyo");
// 	// std::cout << scopycat << king;
// 	// scopycat = king;
// 	// std::cout << scopycat << king;
// 	// std::cout << std::endl << std::endl;

// 	// Victim& lPeon = joe;
// 	// lPeon.getPolymorphed();
// 	// robert.polymorph(lPeon);

// 	// std::cout << std::endl << std::endl;


// 	return 0;
// }