//
// CPP_Mod06_ex02/emabel/21school
//

#include <iostream>
#include <ctime>

class Base
{
public:
	virtual ~Base();
};

Base::~Base() {}

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};

Base *generate(void)	//генерируем рандомный дочерний класс от Base
{
	srand(time(NULL));
	switch(rand() % 3)
	{
		case 0:
			std::cout << " ✔ class A is created!" << std::endl; 
			return new A;
		case 1:
			std::cout << " ✔ class B is created!" << std::endl;  
			return new B;
		case 2:
			std::cout << " ✔ class C is created!" << std::endl; 
			return new C;
	}
	return nullptr;
}


void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p)) //!= nullptr
		std::cout << " *A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << " *B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << " *C" << std::endl;
}

void identify_from_reference(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << " &A" << std::endl;
	if (dynamic_cast<B*>(&p))
		std::cout << " &B" << std::endl;
	if (dynamic_cast<C*>(&p))
		std::cout << " &C" << std::endl;
	// identify_from_pointer(&p);
}

int main()
{
	Base *base = generate();
	std::cout << "    available by pointer:" << std::endl; //смотрим какой дочерний класс от Base создался и доступен по указателю
	identify_from_pointer(base);
	std::cout << "    available by reference:" << std::endl; //смотрим какой дочерний класс от Base создался и доступен по ссылке
	identify_from_reference(*base);

	return (0);
}



// https://ravesli.com/urok-171-dinamicheskoe-privedenie-tipov-operator-dynamic_cast/
// https://ru.stackoverflow.com/questions/547856/%D0%97%D0%B0%D1%87%D0%B5%D0%BC-%D0%BD%D1%83%D0%B6%D0%B5%D0%BD-dynamic-cast
