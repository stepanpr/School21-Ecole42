
//
// CPP_Mod05_ex01/emabel/21school
//

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
class Form;
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
	 	int const _gradeToSign; //оценка, необходимая для подписания
		int const _gradeToExec; //оценка, необходимая для выполнения
		Form();
		
	public:
		/* canonical form */
		Form(std::string const name, int const gradeToSign, int const gradeToExec);
		Form(Form const & src);
		Form &operator= (const Form& rhs);
		virtual ~Form();

		/* getters */
		std::string getName() const;
		int getGradeToSign() const;		//оценка необходимая для подписания 
		int getGradeToExec() const;		//оценка необходимая для исполнения
		bool getIsSigned() const;

		/* methods */

		void beSigned(Bureaucrat & bureaucrat);			//подписать форму (принимает ссылку на бюрократа)

		class GradeTooHighException: public std::exception {	//наследуем стандартное исключение
			virtual const char* what() const throw();			//используем для переопределения what() в производном классе от базового класса std::exception
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<< (std::ostream &os, Form const &rhs); //перегрузка оператора ввода


#endif
