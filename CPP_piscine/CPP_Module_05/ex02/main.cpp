
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



int main() 
{
    Bureaucrat pablo("Pablo", 1); //150

	// std::cout  << std::endl << "---------------NEW-CASE-----------------\n";

    std::cout << std::endl << std::endl << "-------Check-function-execute-for-PresidentialPardonForm-------" << std::endl;
	PresidentialPardonForm antonio("Antonio");
    std::cout << "\e[0;35m(form isSigned before:\e[0m " << antonio.getIsSigned() << "\e[0;35m)\e[0m" << std::endl;	//проверяем подписана ли форма
    pablo.executeForm(antonio);																//пытаемся выполнить
    std::cout << "\e[0;35mPablo sign the form:\e[0m ";
    pablo.signForm(antonio);																//подписываем форму
    std::cout << "\e[0;35m(form isSigned after:\e[0m " << antonio.getIsSigned() << "\e[0;35m)\e[0m" << std::endl;		//проверяем подписана ли форма
    std::cout << "\e[0;35mCheck function execute after sign:\e[0m ";
    pablo.executeForm(antonio);																//выполняем

	// std::cout << std::endl << std::endl << "---------------NEW-CASE-----------------\n";

    std::cout << std::endl << std::endl << "-------Check-function-execute-RobotomyRequestForm-------" << std::endl;
    RobotomyRequestForm hand("hand");
    std::cout << "\e[0;35m(form isSigned before:\e[0m " << hand.getIsSigned() << "\e[0;35m)\e[0m" << std::endl;					//проверяем подписана ли форма
    pablo.executeForm(hand);																	//пытаемся выполнить
    std::cout << "\e[0;35mPablo sign the form:\e[0m ";
    pablo.signForm(hand);
    std::cout << "\e[0;35m(form isSigned after:\e[0m " << hand.getIsSigned() << "\e[0;35m)\e[0m" << std::endl;					//проверяем подписана ли форма
    std::cout << "\e[0;35mCheck function execute after sign:\e[0m ";
    pablo.executeForm(hand);																	//выполняем

	// std::cout << std::endl << std::endl << "---------------NEW-CASE-----------------\n";

    std::cout << std::endl << std::endl << "-------Check-function-execute-ShrubberyCreationForm-------" << std::endl;
    ShrubberyCreationForm forest("forest");
    std::cout << "\e[0;35m(form isSigned before:\e[0m " << forest.getIsSigned() << "\e[0;35m)\e[0m" << std::endl;					//проверяем подписана ли форма
    pablo.executeForm(forest);																	//пытаемся выполнить
    std::cout << "\e[0;35mPablo sign the form:\e[0m ";
    pablo.signForm(forest);
    std::cout << "\e[0;35m(form isSigned after:\e[0m " << forest.getIsSigned() << "\e[0;35m)\e[0m" << std::endl;					//проверяем подписана ли форма
    std::cout << "\e[0;35mCheck function execute after sign:\e[0m ";
    pablo.executeForm(forest);																	//выполняем


    return 0;
}