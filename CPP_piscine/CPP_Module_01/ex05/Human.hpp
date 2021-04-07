
#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

class Human
{
	private:
		Brain brain;    			          //мозг

	public:
		Human();
		~Human();
		
		std::string identify() const;		   //ссылка на метод экземпляра мозга
		 const Brain& getBrain(void) const;    //сылка на мозг
};


#endif