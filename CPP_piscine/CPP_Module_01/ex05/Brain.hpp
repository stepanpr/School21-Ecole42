//
// CPP_Mod01_ex05/21school/emabel
//

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# include <sstream>

class Brain
{
	private:
		int _iq;

	public:
		Brain();
		~Brain();
		std::string identify() const; // метод, возвращающий адрес мозга
};


#endif