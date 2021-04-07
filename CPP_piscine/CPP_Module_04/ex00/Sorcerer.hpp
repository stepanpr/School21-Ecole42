
//
// CPP_Mod04_ex00/emabel/21school
//

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"


class Sorcerer
{
	private:
		std::string _name;
		std::string _title;
		Sorcerer();
	public:
		/* canonical form */
		Sorcerer(std::string const name, std::string const title);
		Sorcerer(Sorcerer const & src);
		Sorcerer &operator= (const Sorcerer& rhs);
		virtual ~Sorcerer();

		/* getters */
		std::string getName() const;
		std::string getTitle() const;

		/* methods */
		void polymorph(Victim const &) const;
		std::string sayHello() const;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &tmp);

#endif
