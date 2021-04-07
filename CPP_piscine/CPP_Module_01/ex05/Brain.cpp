
#include "Brain.hpp"

Brain::Brain()
{
	this->_iq = 100 + (long)this % 50;
	std::cout << "IQ of this Human is "<< this->_iq << std::endl;
}

Brain::~Brain() {}

//формирует и возвращает адрес строки
//std::hex выражает целочисленные значения, вставленные в поток, в шестнадцатеричной основе;
// str("data") записывает в буфер данные как и оператор "<<";
// str() возвращает все содержимое своего буфера в виде строки, в то время как
// оператор ">>" возвращает данные разделяя строку по пробелу (в string мы записываем строку в которой
// отсутствуют пробелы, поэтому записывается целиком строка из buffer;
// приведение this к типу void* вернет нужный адрес, но маленькими символами, тогда как 
// в задании нам нужен адрес формата 0xYYYYYYYY;
// https://ravesli.com/urok-210-potokovye-klassy-i-stroki/#toc-0
std::string Brain::identify() const
{
	std::stringstream buffer;
	std::string string;
	buffer << "0x" << std::uppercase << std::hex << (long)this;
	buffer >> string;

	return (string); 	// или return (buffer.str());
}