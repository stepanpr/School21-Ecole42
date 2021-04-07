
#include "Form.hpp"

//==================================CANONIC=FORM===============================


Form::Form(const std::string name, const int gradeToSign, const int gradeToExec): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (this->_gradeToExec < 1 || this->_gradeToSign < 1)	//проверяем форму при создании
        throw Form::GradeTooHighException();
    if (this->_gradeToExec > 150 || this->_gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) 
{
    if (this->_gradeToExec < 1 || this->_gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (this->_gradeToExec > 150 || this->_gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

Form::~Form() {}

//==================================OVERLOAD=OF=THE=<<==========================


std::ostream &operator<< (std::ostream &os, Form const &rhs)
{
	os << " 📋 " << rhs.getName() << ", form grade required to sign it " << rhs.getGradeToSign() << ", grade required to execute it " << rhs.getGradeToExec() << std::endl;
    return os;
}

//====================================GETTERS===================================


std::string Form::getName() const { return this->_name; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExec() const { return this->_gradeToExec; }
bool Form::getIsSigned() const { return this->_isSigned; }


//====================================ACTIONS===================================


void Form::beSigned(Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;				//проверяем что у бюрократа достаточно высокий Grade чтобы подписать форму
    else
        throw Form::GradeTooLowException();	//иначе бросаем исключение
}


const char *Form::GradeTooHighException::what() const throw()
{
	return "\e[0;33mgrade is too HIGHT!\e[0m";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "\e[0;33mgrade is too LOW!\e[0m";
}

