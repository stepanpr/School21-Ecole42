

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include "Zombie.hpp"

class ZombieHorde
{
private:
	Zombie *zombies;
	int numOfZombies;
	static std::string names[10];
	static std::string types[4];

public:
	ZombieHorde(int N);
	~ZombieHorde(void);

	void announce() const;
};


#endif