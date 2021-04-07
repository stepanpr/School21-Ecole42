//
// CPP_Mod04_ex03/emabel/21school
//

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter
{
	private:
		AMateria*	_materia[4];  //инвентарь на 4 материи
		std::string	_name;
	public:
		/* canonical */
		Character();
		Character(const std::string &name);
		Character( Character const & obj );
		Character&	operator=( Character const & rhs);
		virtual ~Character();
		/* getters */
		virtual std::string const & getName() const;
		/* actions */
		virtual void equip(AMateria* m);	//положить в инвентарь
		virtual void unequip(int idx);		//убрать из инвентаря
		virtual void use(int idx, ICharacter& target);


};

#endif
