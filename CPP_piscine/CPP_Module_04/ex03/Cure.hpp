
#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		/* canonical */
		Cure();
		Cure( Cure const & obj );
		Cure&	operator=( Cure const & rhs);
		virtual ~Cure();
		/* actions */
		virtual AMateria* clone() const;		//клон
		virtual void use(ICharacter& target);	//использование
};

#endif
