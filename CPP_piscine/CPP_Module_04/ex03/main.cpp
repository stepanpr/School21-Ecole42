
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// * shoots an ice bolt at bob *$
// * heals bob's wounds *$

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	// IMateriaSource* sourceOfMateria = new MateriaSource();  	//источник материи
	// sourceOfMateria->learnMateria(new Ice());					//изучаем материю
	// sourceOfMateria->learnMateria(new Cure());					//изучаем материю

	// ICharacter* antonio = new Character("Antonio");				//персонаж 1
	// ICharacter* pablo = new Character("Pablo");					//персонаж 2

	// AMateria* materia = sourceOfMateria->createMateria("ice");	//создаем материю ice
	// antonio->equip(materia);
	// antonio->equip(materia);
	// materia = sourceOfMateria->createMateria("cure");			//создаем материю cure
	// antonio->equip(materia);
	// antonio->equip(materia);
	// // antonio->equip(materia);									//не запишется (>3)

	// antonio->use(0, *pablo);
	// antonio->use(1, *pablo);
	// antonio->use(2, *pablo);
	// antonio->use(3, *pablo);
	// antonio->use(4, *pablo);									// The Materia does not exist...							

	// antonio->unequip(0);
	// antonio->unequip(1);
	// antonio->unequip(2);
	// antonio->unequip(3);
	// antonio->unequip(4);										// The Materia does not exist...

	// delete antonio;
	// delete pablo;
	// delete sourceOfMateria;

	return 0;
}