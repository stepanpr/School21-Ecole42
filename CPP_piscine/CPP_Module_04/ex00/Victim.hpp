

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>
# include <string>

class Victim
{
	private:
		std::string _name;
		Victim();
	public:
		/* canonical form */
		Victim(std::string name);
		Victim(Victim const & src);
		Victim &operator= (const Victim& rhs);
		virtual ~Victim();

		/* getters */
		std::string getName() const;

		/* methods */
		std::string sayHello() const;
		virtual void getPolymorphed () const;	//за счет того что метод getPolymorphed отмечен как виртуальный, 
												//будет выполняться наиболее "дочерний метод", который существует 
												//между родительским и дочерними классами (полиморфизм);
												//дочерний метод будет вызываться тогда, когда совпадает сигнатура
												//(имя, типы параметров и является ли метод константным);
};

std::ostream &operator<<(std::ostream &out, Victim &tmp);

#endif