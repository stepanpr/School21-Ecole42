

#ifndef DOCTOR_HPP
# define DOCTOR_HPP
# include <iostream>
# include <string>
# include "Sorcerer.hpp"
# include "Victim.hpp"

class Doctor : public Victim
{
	private:
		std::string _name;
		Doctor();

	public:
		/* canonical form */
		Doctor(std::string name);
		Doctor(Doctor const & src);
		Doctor &operator= (const Doctor& rhs);
		virtual ~Doctor();

		/* getters */
		std::string getName() const;

		/* methods */
		std::string sayHello() const;
		virtual void getPolymorphed () const;

		// poNymorph
};

std::ostream &operator<<(std::ostream &out, Doctor &tmp);
//при отсутствии функции будет вызываться перегрузка оператора из класса-родителя Victim

#endif