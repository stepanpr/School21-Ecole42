

#include "Intern.hpp"

//==================================CANONIC=FORM===============================

Intern::Intern()	
{
    this->_names[0] = "shrubbery creation";			//инициализирукм массив имен
    this->_names[1] = "robotomy request";
    this->_names[2] = "presidential pardon";
    this->_make[0] = &Intern::makeShruberyCreation;
    this->_make[1] = &Intern::makeRobotomyRequest;
    this->_make[2] = &Intern::makePresidentalPardon;
}


Intern::Intern(const Intern &copy) {
    for (int i = 0; i < 3; i++)
    {
        this->_names[i] = copy._names[i];
        this->_make[i] = copy._make[i];
    }
}

Intern &Intern::operator=(const Intern &op) {
    (void)&op;
    return *this;
}

Intern::~Intern()
{

}

//====================================ACTIONS===================================

Form *Intern::makeShruberyCreation(std::string target)		
{
	return new ShrubberyCreationForm(target);	//возвращает новый экземпляр формы
}

Form *Intern::makeRobotomyRequest(std::string target)
{
	return new RobotomyRequestForm(target);		//возвращает новый экземпляр формы
}

Form *Intern::makePresidentalPardon(std::string target)
{
	return new PresidentialPardonForm(target);	//возвращает новый экземпляр формы
}

Form *Intern::makeForm(std::string formType, std::string target)
{
    int flag = 0;
	for (int i = 0; i < 3; i++)
	{
		if(this->_names[i] == formType)			//если встречаем форму заданного типа, то создаем форму 
		{
            flag = 1;
		    std::cout << " 🎓 Intern creates " << (this->*_make[i])(target)->getName() << std::endl;
			return (this->*_make[i])(target);
		}
	}
	if (flag == 0)								//если форму не встретили, то бросаем ошибку
        throw Intern::NameDoesNotExistException();
	return NULL;
}

const char *Intern::NameDoesNotExistException::what() const throw() {
    return " 📋❌ type of requested form is unikown\n";
}