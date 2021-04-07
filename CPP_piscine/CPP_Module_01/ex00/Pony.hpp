
#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Pony 
{
private:
	std::string name;
	std::string sex;
	std::string breed;
	std::string color;
public:

	Pony(std::string name, std::string sex, std::string breed, std::string color);
	~Pony();
	void getName();  //как зовут
	void getSex();   //какой пол
	void getColor(); //какой цвет
	void getBreed(); //какая порода
	void trotting(); //бег рысью
	void eating();   //прием пищи
};

#endif