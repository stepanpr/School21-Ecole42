//
// CPP_Mod01_ex07/21school/emabel
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int check_filename(std::string &f)
{
	std::string res;

	for(int i = 0; i < f.length(); i++)
	{
		if (f[i] == '.' && f[i+1] == 'r' 
		&& f[i+2] == 'e' && f[i+3] == 'p' 
		&& f[i+4] == 'l' && f[i+5] == 'a' 
		&& f[i+6] == 'c' && f[i+7] == 'e')
			return(1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac < 4 || ac > 4)
	{
		std::cout << "error: please, enter three arguments: |filename| |s1| |s2|" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string current_string;
	std::stringstream buffer;

	std::ifstream ifs(filename);				//открываем поток
	if(!ifs.good())								//если поток не открылся, возвращаем ошибку
	{
		std::cout << "error: can't open file with name " << filename << std::endl;
		return (1);
	}

	while(ifs)
	{
		if (!(ifs >> current_string))			//читаем строку
    	{   
        	ifs.close();
       	 	break;
    	}
		if (current_string == s1)				//если встречаем s1, то заменяем на s2
			current_string = s2;
		buffer << current_string << " ";		//записываем в buffer
	}

	if ((check_filename(filename)))				//ошибка если читаем из файла с расширением .replace
	{
		std::cout << "error: can't create \"" 
		<< filename << "\": file already exists!" << std::endl;
		return (1);
	}
	std::ofstream ofs(filename + ".replace"); 	//открываем поток на запись
	if (!ofs.good())							//если поток не открылся, возвращаем ошибку
	{
		std::cout << "error: can't open file with name " 
		<< filename << ".replace" << std::endl;
		return (1);
	}
	ofs << buffer.str() << std::endl;			//записываем содержимое buffer
	ofs.close();

	return (0);
}
