
#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

// me has 40 AP and is unarmed$
// * click click click *$
// me has 40 AP and wields a Plasma Rifle$
// me attacks RadScorpion with a Power Fist$
// * pschhh... SBAM! *$
// me has 32 AP and wields a Power Fist$
// me has 32 AP and wields a Plasma Rifle$
// me attacks RadScorpion with a Plasma Rifle$
// * piouuu piouuu piouuu *$
// me has 27 AP and wields a Plasma Rifle$
// me attacks RadScorpion with a Plasma Rifle$
// * piouuu piouuu piouuu *$
// * SPROTCH *$
// me has 22 AP and wields a Plasma Rifle$

int main()
{
	{
		Character* me = new Character("me");
		std::cout << *me;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		me->equip(pr);
		std::cout << *me;
		me->equip(pf);
		me->attack(b);
		std::cout << *me;
		me->equip(pr);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
	}

	// std::cout << "=======TESTS=======" << std::endl;
	// Character* duke = new Character("DukeNukem");
	// AWeapon* pf = new PowerFist();		//50 of damege
	// Enemy* mutant = new SuperMutant(); 	//170 HP
	// std::cout << *duke;
	// duke->equip(pf);
	// std::cout << *duke;
	// duke->attack(mutant);	
	// duke->attack(mutant);
	// duke->attack(mutant);
	// duke->attack(mutant);

	// Enemy* scorpion = new RadScorpion();
	// duke->attack(scorpion);
	// duke->attack(scorpion);				//no attack 0 AP
	// duke->attack(scorpion);				//no attack 0 AP
	// duke->attack(scorpion);				//no attack 0 AP

	// std::cout << *duke;
	// duke->recoverAP();					//recover + 10 AP
	// std::cout << *duke;
	// duke->recoverAP();					//recover + 10 AP
	// std::cout << *duke;
	// duke->recoverAP();					//recover + 10 AP
	// std::cout << *duke;
	// duke->recoverAP();					//recover + 10 AP
	// std::cout << *duke;

	// duke->attack(scorpion);				//scorpion is die
	// std::cout << *duke;					

	return 0;
}
