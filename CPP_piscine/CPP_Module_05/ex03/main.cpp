	#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"



int main() 
{

	Bureaucrat pablo("Pablo", 1);
	Intern antonio;
	
	Form *form1;
	form1 = antonio.makeForm("presidential pardon", "juan");	//интерн создает форму "presidential pardon"
	std::cout << *form1 << std::endl;
    Form *form2;
    form2 = antonio.makeForm("robotomy request", "hand");		//интерн создает форму "robotomy request"
    std::cout << *form2 << std::endl;
    Form *form3;
    form3 = antonio.makeForm("shrubbery creation", "house");	//интерн создает форму "shrubbery creation"
    std::cout << *form3 << std::endl;

    std::cout << "----------------------------------------\n"; 	//бюрократ подписывает форму
    pablo.signForm(*form1);
    pablo.executeForm(*form1);
    std::cout << "----------------------------------------\n";	//бюрократ подписывает форму
    pablo.signForm(*form2);
    pablo.executeForm(*form2);
    std::cout << "----------------------------------------\n";	//бюрократ подписывает форму
    pablo.signForm(*form3);
    pablo.executeForm(*form3);
    std::cout << "----------------------------------------\n";

	
	Form *unikown_form;
	try
    {
        unikown_form = antonio.makeForm("xxxxxxxxx", "xxx");
    }
	catch (std::exception const &e)
    {
	    std::cerr << e.what() << std::endl;
    }
	

    return 0;
}