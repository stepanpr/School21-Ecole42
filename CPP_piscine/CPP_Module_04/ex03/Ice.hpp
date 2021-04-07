
#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class	Ice : public AMateria
{
	public:
		/* canonical */
		Ice();
		Ice(Ice const & obj);
		Ice & operator=(Ice const & rhs);
		virtual ~Ice();
		/* actions */
		virtual AMateria* clone() const;		//клон
		virtual void use(ICharacter& target);	//использование
};

#endif