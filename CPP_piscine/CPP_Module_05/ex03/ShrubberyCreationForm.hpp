
//
// CPP_Mod05_ex03/emabel/21school
//

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form 
{
	private:
		std::string _target;
		ShrubberyCreationForm();
	public:
		/* canonical form */
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &op);
		/* actions */
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<< (std::ostream &os, ShrubberyCreationForm const &rhs);

#endif
