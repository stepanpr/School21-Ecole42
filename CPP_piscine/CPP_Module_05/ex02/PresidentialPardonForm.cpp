
#include "PresidentialPardonForm.hpp"

//==================================CANONIC=FORM===============================

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5) {
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form("PresidentialPardonForm", 25, 5) {
    this->_target = copy._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &op) {
    if (this != &op)
        this->_target = op._target;
    return *this;
}

//====================================ACTIONS===================================

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getGradeToExec())
        throw Form::GradeTooLowException();	//если grade на выполнение меньше, то бросаем ошибку
	else
    	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<< (std::ostream &os, PresidentialPardonForm const &rhs)
{
    os << rhs.getName() << ", form grade required to sign it " << rhs.getGradeToSign() << ", grade required to execute it " << rhs.getGradeToExec() << std::endl;
    return os;
}
