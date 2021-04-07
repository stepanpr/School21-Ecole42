
//
// CPP_Mod05_ex03/emabel/21school
//

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm: public Form 
{
	private:
		std::string _target;
		RobotomyRequestForm();
	public:
		/* canonical form */
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator= (const RobotomyRequestForm &op);
		/* actions */
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<< (std::ostream &os, RobotomyRequestForm const &rhs);

#endif