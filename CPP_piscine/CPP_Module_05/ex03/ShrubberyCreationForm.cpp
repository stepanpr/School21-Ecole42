

#include "ShrubberyCreationForm.hpp"

//==================================CANONIC=FORM===============================

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form("ShrubberyCreationForm", 145, 137) {
    this->_target = copy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op) {
    if (this != &op)
        this->_target = op._target;
    return *this;
}

//====================================ACTIONS===================================

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > this->getGradeToExec())
    {
        throw Form::GradeTooLowException();     //если grade на выполнение меньше, то бросаем ошибку
        return;
    }
    std::string name = this->_target + "_shrubbery";
    std::ofstream out(name);
    if (out.is_open())
    {	 
		if (rand() % 2)
		{  
			out << "          # #### ####			" << std::endl;
			out << "        ### \\/#|### |/####		" << std::endl;
			out << "       ##\\/#/ \\||/##/_/##/_#	" << std::endl;
			out << "     ###  \\/###|/ \\/ # ###	" << std::endl;
			out << "   ##_\\_#\\_\\## | #/###_/_####" << std::endl;
			out << "  ## #### # \\ #| /  #### ##/##	" << std::endl;
			out << "   __#_--###`  |{,###---###-~	" << std::endl;
			out << "             \\ }{				" << std::endl;
			out << "              }}{				" << std::endl;
			out << "              }}{				" << std::endl;
			out << "              {{}				" << std::endl;
			out << "        , -=-~{ .-^- _			" << std::endl;
			out << "              `}				" << std::endl;
			out << "               {				" << std::endl;
		}
		else 
		{
			out << "         * \n"
				"        /|\\\n"
				"       /*|*\\\n"
				"      /*/|\\*\\\n"
				"     /*/X|X\\*\\\n"
				"    /*/X/|\\X\\*\\\n"
				"   /*/X/*|*\\X\\*\\ \n"
				"  /*/X/*/|\\*\\X\\*\\\n"
				" /*/X/*/X|X\\*\\X\\*\\\n"
				"/*/X/*/X/|\\X\\*\\X\\*\\\n"
				"        |X|      \n"
				"        |X|    ";
		}
        out.close();
    }
    else
        std::cerr << "fail! Can't write tree. " << std::endl;
}


//==================================OVERLOAD=OF=THE=<<==========================

std::ostream &operator<< (std::ostream &os, ShrubberyCreationForm const &rhs)
{
    os << rhs.getName() << ", form grade required to sign it " << rhs.getGradeToSign() << ", grade required to execute it " << rhs.getGradeToExec() << std::endl;
    return os;
}



//https://www.cplusplus.com/reference/fstream/ofstream/is_open/