
#include "RobotomyRequestForm.hpp"
#include <ctime>

//==================================CANONIC=FORM===============================

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45) {
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form("RobotomyRequestForm", 72, 45) {
    this->_target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &op) {
    if (this != &op)
        this->_target = op._target;
    return *this;
}

//====================================ACTIONS===================================

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw Form::GradeTooLowException();		//если grade на выполнение меньше, то бросаем ошибку
        return;
    }
    std::cout << "...dr dr dr dr dr dr dr dr dr..." << std::endl;
    std::srand(std::time(nullptr));
    int random = std::rand() % 2;
    if (random)   //if (rand() % 2)
        std::cout << " 🦾 " << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << " 🙅 FAIL! " << this->_target << " has not been robotomized " << std::endl;
}

//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<< (std::ostream &os, RobotomyRequestForm const &rhs)
{
    os << rhs.getName() << ", form grade required to sign it " << rhs.getGradeToSign() << ", grade required to execute it " << rhs.getGradeToExec() << std::endl;
    return os;
}