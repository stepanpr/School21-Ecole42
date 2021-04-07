

//
// CPP_Mod05_ex00/emabel/21school
//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	private:
		std::string _name;
	 	int _grade;
		Bureaucrat();
	public:
		/* canonical form */
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat &operator= (const Bureaucrat& rhs);
		~Bureaucrat();

		/* getters */
		std::string getName() const;
		int getGrade() const;

		/* methods */
		void incrementGrade();
		void decrementGrade();


		class GradeTooHighException: public std::exception {	//наследуем стандартное исключение
			virtual const char* what() const throw();			//используем для переопределения what() в производном классе от базового класса std::exception
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};


};

std::ostream &operator<< (std::ostream &os, Bureaucrat const &rhs); //перегрузка оператора ввода


#endif

// https://ravesli.com/urok-182-obrabotka-isklyuchenij/
// https://stackoverflow.com/questions/5230463/what-does-this-function-declaration-mean-in-c


