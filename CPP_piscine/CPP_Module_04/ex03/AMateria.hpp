//
// CPP_Mod04_ex03/emabel/21school
//

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	private:
		unsigned int	_xp;
		std::string 	_type;
	public:
		/* canonical */
		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & obj );
		AMateria&	operator=( AMateria const & rhs);
		virtual ~AMateria();
		/* getters */
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		/* setters */
		void	setType(std::string const & type);
		void	setXp(unsigned int xp);
		/* actions */
		virtual AMateria* clone() const = 0; //абстрактный класс, функция определяется в дочерних классах
		virtual void use(ICharacter& target);
};

#endif
