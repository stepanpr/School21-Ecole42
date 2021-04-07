
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

// Tactical Marine ready for battle!$
// * teleports from space *$
// For the holy PLOT!$
// * attacks with a bolter *$
// * attacks with a chainsword *$
// This code is unclean. PURIFY IT!$
// * does nothing *$
// * attacks with chainfists *$
// Aaargh...$
// I'll be back...$

int main()
{
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	//MORE TESTS
	// ISpaceMarine *a = new TacticalMarine;
	// ISpaceMarine *b = new AssaultTerminator;
	// ISpaceMarine *c = new TacticalMarine;
	// ISpaceMarine *d = new AssaultTerminator;
	// ISpaceMarine *e = new TacticalMarine;
	// ISquad *group = new Squad;
	// group->push(a);
	// group->push(b);
	// group->push(c);
	// group->push(d);
	// group->push(e);
	// std::cout << " ~ marines in the group: "<< group->getCount() << std::endl;

	// ISquad *NewGroup = new Squad;
	// for (int i = 0; i < group->getCount(); ++i) //записываем юнитов в новую группу
	// {
	// 	NewGroup->push(group->getUnit(i));
	// }
	// std::cout << " ~ marines in the NEW group: "<< group->getCount() << std::endl;
	// std::cout << " ~ ATTACK ~ " << std::endl;
	// for (int i = 0; i < NewGroup->getCount(); ++i) //вызываем функции атаки каждого из юнитов
	// {
	// 	NewGroup->getUnit(i)->battleCry();
	// 	NewGroup->getUnit(i)->rangedAttack();
	// 	NewGroup->getUnit(i)->meleeAttack();
	// }
	return 0;
}
