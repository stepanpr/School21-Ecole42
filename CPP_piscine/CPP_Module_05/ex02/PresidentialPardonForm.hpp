
//
// CPP_Mod05_ex02/emabel/21school
//

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm: public Form 
{
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		/* canonical form */
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator= (const PresidentialPardonForm &op);
		/* actions */
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<< (std::ostream &os, PresidentialPardonForm const &rhs);

#endif
