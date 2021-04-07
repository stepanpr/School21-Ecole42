
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{	
	//переподписывание уже подписанной формы
	std::cout << std::endl << std::endl << "---------------NEW-CASE-----------------\n";
    Bureaucrat Pablo("Pablo", 21);
    Form Document("Document", 21, 12);
	std::cout << Pablo;
    std::cout << Document;
    std::cout << "----------------------------------------\n";		//подписываем форму
    std::cout << "Pablo signs form... " << std::endl;
    std::cout << "(form isSigned before: " << Document.getIsSigned() << ")"<< std::endl;
    Pablo.signForm(Document);
    std::cout << "(form isSigned after: " << Document.getIsSigned() << ")" << std::endl;
    std::cout << "----------------------------------------\n";		//пытаемся подписать еще раз
    std::cout << "Pablo signs form again... " << std::endl;
    std::cout << "(form isSigned before: " << Document.getIsSigned() << ")"<< std::endl;
    Pablo.signForm(Document);


	//слишком низкий grade у бюрократа
	std::cout << std::endl << std::endl << "---------------NEW-CASE-----------------\n";
    Bureaucrat antonio("Antonio", 42);
    Form declaration("Declaraction", 2, 45);
    std::cout << antonio;
	std::cout << declaration;
	std::cout << "----------------------------------------\n";
    antonio.signForm(declaration);				//не может подписать (низкий grade)


	//создание невалидной формы
	std::cout << std::endl << std::endl << "---------------NEW-CASE-----------------\n";
    try
    {
        Form formLow("formLow", 170, 1);		//слишком низкий grade
    }
    catch (std::exception const &e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }
    std::cout << "----------------------------------------\n";
    try
    {
        Form formHigh("formHigh", 10, 0);		//слишком высокий grade
    }
    catch (std::exception const &e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }


    return 0;
}
