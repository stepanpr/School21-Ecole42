
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

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
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

void Bureaucrat::signForm(Form & form)
{
	if(form.getIsSigned())    //если форма уже подписана, то ее нельза подписать
    {
        std::cout << " ❗️ " << this->_name << " cannot sign " << form.getName() << " because isSigned is " << form.getIsSigned() << std::endl;
        return;
    }
    try
    {
        form.beSigned(*this);		//подписываем форму
        std::cout << " 📝 " << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(std::exception const &e)
    {								//либо если возвращается исключение, то выводим ошибку
        std::cerr << " ❌ " << this->_name << " cannot sign " << form.getName() << " because "<< e.what() << std::endl;
    }
}


void Bureaucrat::executeForm(const Form &form) {
    if(!form.getIsSigned())
    {
        std::cout << " ❗️ " << this->_name << " cannot execute " << form.getName() << " because it is not signed" << std::endl;
        return;
    }
    try
    {
        form.execute(*this);
        std::cout << " 🔆 " << this->_name << " executes " << form.getName() << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << " ❌ " << this->_name << " cannot execute " << form.getName() << " because "<< e.what() << std::endl;
    }
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return " 🤦 \e[0;33m...grade is too HIGHT...\e[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return " 🤷‍ \e[0;33m...grade is too LOW...\e[0m";
}

