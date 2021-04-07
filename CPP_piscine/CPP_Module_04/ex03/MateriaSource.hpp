
//
// CPP_Mod04_ex03/emabel/21school
//

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];
	public:
		/* canonical */
		MateriaSource();
		MateriaSource(MateriaSource const & obj);
		MateriaSource& operator=(MateriaSource const & rhs);
		virtual~MateriaSource();
		/* actions */
		virtual void		learnMateria(AMateria*);					//копирует Materia, переданную в качестве параметра
		virtual AMateria*	createMateria(std::string const & type);	//возвращает новую Materia, тип которой равен type
};

#endif