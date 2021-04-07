
//
// CPP_Mod06_ex01/emabel/21school
//

// Сериализация - процесс перевода какой-либо структуры данных в последовательность битов. 
// Обратной к операции сериализации является операция десериализации (структуризации) — 
// восстановление начального состояния структуры данных из битовой последовательности.
// https://ru.wikipedia.org/wiki/%D0%A1%D0%B5%D1%80%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F#:~:text=%D0%A1%D0%B5%D1%80%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F%20(%D0%B2%20%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B8)%20%E2%80%94%20%D0%BF%D1%80%D0%BE%D1%86%D0%B5%D1%81%D1%81,%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D1%8B%20%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85%20%D0%B8%D0%B7%20%D0%B1%D0%B8%D1%82%D0%BE%D0%B2%D0%BE%D0%B9%20%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

struct Data
{
    std::string s1;
    int         n;
    std::string s2;
};

std::string randStr(std::string &str)
{
	std::string symbols = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
	for (int i = 0; i < 8; i ++)									//заполнили 8 байтов 
		str[i] = symbols[rand() % symbols.length()];
	return (str);
}


void *serialize(void)
{
	srand(time(NULL));
	int size = sizeof(std::string) * 2 + sizeof(int); 				//24(string) + 4(int) + 24(string) 
	char *raw = new char[size];  									//размер строки (на 8 char) = 24 байта (macOS, на Ubuntu 32 байта); 

	int number = std::rand() % 123456;
	std::string string(8, '\0');

	randStr(string);
	std::cout << " s1: " << string << std::endl;					//записываем s1				
	for (int i = 0; i < 8; i++)
		raw[i] = string[i];

	std::cout << "  n: " << number << std::endl;
	*reinterpret_cast<int*>(raw + sizeof(std::string)) = number; 	//разыменовываем указатель и записываем рандомный int num после s1
	
	randStr(string);
	std::cout << " s2: " << string << std::endl;		
	for (int i = 0; i < 8; i++)										//записываем s2 после num (i + 12)
		raw[i + 12] = string[i];

	std::cout << " size of raw: " << size << std::endl;           	//размер массива (на убунте размер строки 32 байта, на маке 24)
    return (raw);    
}

Data *deserialize(void * raw)
{
	Data *data = new Data;
	data->s1 = std::string(reinterpret_cast<char*>(raw), 8);		//преобразуем данные void* raw в char*, а char* конвертируем в int и string, и затем записываем в структуру
	data->n = *reinterpret_cast<int *>(static_cast<char*>(raw) + sizeof(std::string));
	data->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);
	return data;
}

int main(void)
{
	std::cout << "-----------SERIALIZE-----------" << std::endl;
    void *raw = serialize();
	std::cout << "----------DESERIALISE----------" << std::endl;
    Data* data = deserialize(raw);
	std::cout << " s1: " << data->s1 << std::endl;
	std::cout << "  n: " << data->n << std::endl;
	std::cout << " s2: " << data->s2 << std::endl;
    delete data;
    return 0;
}
