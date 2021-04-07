

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include <string>
# include "Sorcerer.hpp"
# include "Victim.hpp"

class Peon : public Victim
{
	private:
		std::string _name;
		Peon();

	public:
		/* canonical form */
		Peon(std::string name);
		Peon(Peon const & src);
		Peon &operator= (const Peon& rhs);
		virtual ~Peon();

		/* getters */
		std::string getName() const;

		/* methods */
		std::string sayHello() const;
		virtual void getPolymorphed () const;

		// poNymorph
};

std::ostream &operator<<(std::ostream &out, Peon &tmp);
// будет вызываться перегрузка оператора из класса-родителя Victim

#endif