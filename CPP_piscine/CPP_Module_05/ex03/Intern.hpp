
//
// CPP_Mod05_ex03/emabel/21school
//

#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	std::string _names[3];
	Form *(Intern::*_make[3])(std::string target);		//массив указателей на функции

public:
	/* canonical form */
	Intern();
    Intern(const Intern &copy);
    Intern &operator= (const Intern &op);
	~Intern();
	/* actions */
	Form *makeShruberyCreation(std::string target);
	Form *makeRobotomyRequest(std::string target);
	Form *makePresidentalPardon(std::string target);
	Form *makeForm(std::string formType, std::string target);  //передаем тип и цель для формы

    class NameDoesNotExistException: public std::exception{
        virtual const char* what() const throw();
    };

};


#endif 





// https://www.bestprog.net/ru/2017/04/30/%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D1%82%D0%B5%D0%BB%D0%B8-%D1%87%D0%B0%D1%81%D1%82%D1%8C-5-%D0%B2%D1%8B%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D0%B0%D0%BC%D1%8F%D1%82%D0%B8-%D0%B4%D0%BB%D1%8F/
// https://ravesli.com/urok-82-ukazateli-i-massivy/