
#include "Bureaucrat.hpp"

//==================================CANONIC=FORM===============================

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < 1)								//при создании экземпляра класса, проверяем исходные параметры на исключения
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();		//при создании экземпляра класса, проверяем исходные параметры на исключения
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
  	if (this != &rhs)
        this->_grade = rhs._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

//==================================OVERLOAD=OF=THE=<<==========================


std::ostream &operator<< (std::ostream &os, Bureaucrat const &rhs)
{
	os << " ✅ "<< rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}

//====================================GETTERS===================================

std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

//====================================ACTIONS===================================


void Bureaucrat::incrementGrade()	//увеличиваем в сторону 0 по сабджекту
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return " 🤦 ...grade is too HIGHT...";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return " 🤷‍ ...grade is too LOW...";
}



